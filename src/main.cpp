#include <arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// #define D5 14
// #define D6 12
// #define D7 13

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

// SDA => D2
// SCK => D1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup()
{
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);
  // Clear the buffer
  display.clearDisplay();

  Serial.println("Hello world");
  display.println("Hello world");
  display.display();
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
} // end of setup

void loop()
{

  display.clearDisplay();
  display.setCursor(0, 0); // Start at top-left corner

  display.printf("value : %d", analogRead(A0));
  display.display();
  delay(10);
  display.println("ok");
  display.display();
  if (digitalRead(D5) == HIGH)
  {

    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
  }
  else
  {
    digitalWrite(D6, HIGH);

    digitalWrite(D7, LOW);
  }
}