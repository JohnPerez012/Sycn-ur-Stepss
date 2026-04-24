#define BUTTON1_PIN 4
#define BUTTON2_PIN 5

bool lastStateBtn1 = HIGH;
bool lastStateBtn2 = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
}

void loop() {
  bool currentBtn1 = digitalRead(BUTTON1_PIN);
  bool currentBtn2 = digitalRead(BUTTON2_PIN);

  // Button 1 pressed
  if (lastStateBtn1 == HIGH && currentBtn1 == LOW) {
    Serial.println("Button One Pressed");
  }

  // Button 2 pressed
  if (lastStateBtn2 == HIGH && currentBtn2 == LOW) {
    Serial.println("Button Two Pressed");
  }

  lastStateBtn1 = currentBtn1;
  lastStateBtn2 = currentBtn2;

  delay(85); // simple debounce
} 
