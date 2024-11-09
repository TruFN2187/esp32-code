#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display configuration
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// I Used these pins as the ESP32 module I am using did not have t
// the default pins available.
#define SDA_PIN 45
#define SCL_PIN 48
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // Address for 128x64 screen

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int batteryPin = 4; // ADC pin for battery voltage reading (GPIO4 corresponds to ADC1_CH3)
const float R1 = 10000.0; // Resistor R1 in the voltage divider
const float R2 = 10000.0; // Resistor R2 in the voltage divider

void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  int rawValue = analogRead(batteryPin);
  float voltage = (rawValue / 4095.0) * 3.3 * ((R1 + R2) / R2);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Battery Voltage: ");
  display.print(voltage);
  display.print(" V");
  display.display();

  delay(1000); // Update every second
}
