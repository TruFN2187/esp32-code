#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define your custom SDA and SCL pins
#define SDA_PIN 45
#define SCL_PIN 48

// I2C address of the display
#define OLED_I2C_ADDRESS 0x3C

// Reset pin (if you have one, otherwise -1)
#define OLED_RESET -1

// Create an instance of the display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Initialize I2C with custom SDA and SCL pins
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize the display
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the buffer
  display.clearDisplay();
  
  // Display "Hello, World!" message
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.println(F("Hello, world! Today is a good day!"));
  
  // Display the buffer on the screen
  display.display();
}

void loop() {
  // Nothing to do here
}
