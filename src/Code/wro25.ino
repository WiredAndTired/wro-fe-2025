#include <TFT_eSPI.h>
#include <SPI.h>
#include <EEPROM.h>

TFT_eSPI tft = TFT_eSPI();

// Menu items
const char* menu[] = {"First round", "Second round", "Steering", "Speed", "Gyro"};
const int menuLength = sizeof(menu) / sizeof(menu[0]);
int selectedItem = 0;

// Button pins
const int downButton = 0;
const int enterButton = 35;

// Debounce variables
unsigned long lastButtonPressTime = 0;
unsigned long debounceDelay = 200; // debounce delay in milliseconds
unsigned long downButtonPressTime = 0; // Track down button press duration
unsigned long downButtonHoldDuration = 2000; // 2 seconds to exit submenu

bool inSubMenu = false; // Flag to track if we are in submenu

// EEPROM constants
const int eepromStateAddress = 0; // EEPROM address to store menu state (0 = main menu, 1 = submenu)
const int eepromSelectedItemAddress = 1; // EEPROM address to store selected menu item

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  pinMode(downButton, INPUT_PULLUP);
  pinMode(enterButton, INPUT_PULLUP);

  // Initialize EEPROM
  EEPROM.begin(512); // Initialize EEPROM with size (this may vary)

  // Read the state from EEPROM (0 = main menu, 1 = submenu)
  inSubMenu = EEPROM.read(eepromStateAddress) == 1;

  // Read the selected item from EEPROM
  selectedItem = EEPROM.read(eepromSelectedItemAddress);

  // If in submenu, start from submenu state
  if (inSubMenu) {
    enterSubMenu(); // Enter the submenu directly
  } else {
    drawMenu(); // Show the main menu
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Enter button handling (Enter submenu)
  if (digitalRead(enterButton) == LOW && currentMillis - lastButtonPressTime > debounceDelay) {
    if (!inSubMenu) {
      enterSubMenu(); // Enter submenu when enter button is pressed
    }
    lastButtonPressTime = currentMillis; // Update the last button press time
  }

  // Down button handling (Hold to exit submenu)
  if (digitalRead(downButton) == LOW && currentMillis - lastButtonPressTime > debounceDelay) {
    if (inSubMenu) {
      // If in submenu, check if held for 2 seconds
      if (downButtonPressTime == 0) {
        downButtonPressTime = currentMillis; // Start tracking the hold time
      } else if (currentMillis - downButtonPressTime >= downButtonHoldDuration) {
        // Exit submenu after holding for 2 seconds
        exitSubMenu();
      }
    } else {
      selectedItem = (selectedItem + 1) % menuLength;
      drawMenu();
    }
    lastButtonPressTime = currentMillis; // Update the last button press time
  } else if (digitalRead(downButton) == HIGH && downButtonPressTime > 0) {
    // Reset the down button press time if button is released before hold time
    downButtonPressTime = 0;
  }
}

void drawMenu() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(4);
  int textHeight = tft.fontHeight(4);
  int spacing = textHeight - 2; // Reduce spacing to fit all items
  
  for (int i = 0; i < menuLength; i++) {
    int textWidth = tft.textWidth(menu[i], 4);
    int x = 10;
    int y = 10 + (i * spacing); // Adjusted spacing to fit all items
    
    if (i == selectedItem) {
      tft.fillRect(x, y, textWidth, textHeight, TFT_WHITE); // Highlight only the text
      tft.setTextColor(TFT_BLACK, TFT_WHITE);
    } else {
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
    }
    tft.drawString(menu[i], x, y, 4);
  }
}

void enterSubMenu() {
  inSubMenu = true; // Set the flag that we are in the submenu
  EEPROM.write(eepromStateAddress, 1); // Store the state as submenu (1) in EEPROM
  EEPROM.write(eepromSelectedItemAddress, selectedItem); // Store the current selected item in EEPROM
  EEPROM.commit(); // Commit the changes to EEPROM
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Entering: ", 10, 20, 4);
  tft.drawString(menu[selectedItem], 10, 50, 4);
}

void exitSubMenu() {
  inSubMenu = false; // Set the flag to false indicating we are exiting the submenu
  EEPROM.write(eepromStateAddress, 0); // Store the state as main menu (0) in EEPROM
  EEPROM.commit(); // Commit the change to EEPROM
  drawMenu(); // Return to the main menu
  delay(500); // Delay to make the transition smoother
  downButtonPressTime = 0; // Reset the down button hold time
}
