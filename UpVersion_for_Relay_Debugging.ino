#define BTN1 4
#define BTN2 5
#define RELAY 16

bool lastBtn1 = HIGH;
bool lastBtn2 = HIGH;

// CHANGE THIS if your relay behaves opposite
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

void setup() {
  Serial.begin(115200);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, RELAY_OFF); // start OFF
}

void loop() {
  bool btn1 = digitalRead(BTN1);
  bool btn2 = digitalRead(BTN2);

  // BUTTON 1 → RELAY ON (OPEN)
  if (btn1 == LOW && lastBtn1 == HIGH) {
    Serial.println("Button 1: RELAY ON (OPEN)");
    digitalWrite(RELAY, RELAY_ON);
  }

  // BUTTON 2 → RELAY OFF (CLOSE)
  if (btn2 == LOW && lastBtn2 == HIGH) {
    Serial.println("Button 2: RELAY OFF (CLOSE)");
    digitalWrite(RELAY, RELAY_OFF);
  }

  lastBtn1 = btn1;
  lastBtn2 = btn2;

  delay(50);
}
