#include <Adafruit_NeoPixel.h>

#define BTN1 4
#define BTN2 5

#define LED_PIN 48   // MOST ESP32-S3 boards use GPIO48
#define NUMPIXELS 1

Adafruit_NeoPixel pixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

bool lastBtn1 = HIGH;
bool lastBtn2 = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  pixel.begin();
  pixel.clear();
  pixel.show();
}

void loop() {
  bool btn1State = digitalRead(BTN1);
  bool btn2State = digitalRead(BTN2);

  // Button 1 → RED
  if (btn1State == LOW && lastBtn1 == HIGH) {
    Serial.println("Button 1 Pressed");
    pixel.setPixelColor(0, pixel.Color(255, 0, 0));
    pixel.show();
  }

  // Button 2 → BLUE
  if (btn2State == LOW && lastBtn2 == HIGH) {
    Serial.println("Button 2 Pressed");
    pixel.setPixelColor(0, pixel.Color(0, 0, 255));
    pixel.show();
  }

  // No press → OFF
  if (btn1State == HIGH && btn2State == HIGH) {
    pixel.clear();
    pixel.show();
  }

  lastBtn1 = btn1State;
  lastBtn2 = btn2State;

  delay(50);
}
