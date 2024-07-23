// STM32 Nucleo-C031C6 I2C and LED Example
// Simulation: https://wokwi.com/projects/365421666618061313

#include "LiquidCrystal_I2C.h"

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4
#define LED_PIN     PA4  // Assume the LED is connected to PA4 (adjust if different)

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, STM32!");

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello, STM32!");
  lcd.setCursor(5, 2);
  lcd.print("Welcome to");
  lcd.setCursor(7, 3);
  lcd.print("Wokwi!");

  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  delay(500);                   // Wait for 500ms
  digitalWrite(LED_PIN, LOW);   // Turn LED off
  delay(500);                   // Wait for 500ms
}