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
unsigned long buttonPressTime = 0; // Track both buttons press duration
unsigned long buttonsHoldDuration = 2000; // 2 seconds to exit submenu when both buttons are held

bool inSubMenu = false; // Flag to track if we are in submenu

// EEPROM constants
const int eepromStateAddress = 0; // EEPROM address to store menu state (0 = main menu, 1 = submenu)
const int eepromSelectedItemAddress = 1; // EEPROM address to store selected menu item
const int eepromSpeedAddress = 2; // EEPROM address to store speed value

int speed = 0; // Initial speed value

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

  // Read the speed from EEPROM
  speed = EEPROM.read(eepromSpeedAddress);

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

  // Both buttons pressed and held for 2 seconds to exit submenu
  if (digitalRead(downButton) == LOW && digitalRead(enterButton) == LOW) {
    if (buttonPressTime == 0) {
      buttonPressTime = currentMillis; // Start tracking the hold time
    }
    // If both buttons are held for 2 seconds, exit submenu
    else if (currentMillis - buttonPressTime >= buttonsHoldDuration) {
      exitSubMenu();
    }
  } else if (digitalRead(downButton) == HIGH || digitalRead(enterButton) == HIGH) {
    // Reset the button press time if any button is released before hold time
    buttonPressTime = 0;
  }

  // Down button handling (Move through menu)
  if (digitalRead(downButton) == LOW && currentMillis - lastButtonPressTime > debounceDelay) {
    if (!inSubMenu) {
      selectedItem = (selectedItem + 1) % menuLength;
      drawMenu();
    }
    lastButtonPressTime = currentMillis; // Update the last button press time
  }

  // Speed adjustment in Speed submenu
  if (inSubMenu && selectedItem == 3) {  // When we are in the "Speed" submenu

    
    if (digitalRead(downButton) == HIGH && digitalRead(enterButton) == LOW) {
      // Down button is pressed, increase speed by 2
      speed = min(255, speed + 1); // Increase speed by 2 (make sure it doesn't exceed 255)
      updateSpeedDisplay();
      delay(200); // Give a small delay to avoid multiple triggers due to bouncing
    }

    if (digitalRead(enterButton) == HIGH && digitalRead(downButton) == LOW) {
      // Enter button is pressed, decrease speed by 2
      speed = max(0, speed - 1); // Decrease speed by 2 (make sure it doesn't go negative)
      updateSpeedDisplay();
      delay(200); // Give a small delay to avoid multiple triggers due to bouncing
    }
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
  
  if (selectedItem == 3) { // If we are in the Speed submenu
    updateSpeedDisplay();
  }
}

void exitSubMenu() {
  inSubMenu = false; // Set the flag to false indicating we are exiting the submenu
  EEPROM.write(eepromStateAddress, 0); // Store the state as main menu (0) in EEPROM
  EEPROM.write(eepromSpeedAddress, speed); // Save the speed value in EEPROM
  EEPROM.commit(); // Commit the change to EEPROM
  drawMenu(); // Return to the main menu
  delay(500); // Delay to make the transition smoother
  buttonPressTime = 0; // Reset the button hold time
}

void updateSpeedDisplay() {
  tft.fillRect(10, 100, 200, 30, TFT_BLACK); // Clear the previous speed display
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Speed: " + String(speed), 10, 100, 4); // Display the new speed
}
