#define RELAY_PIN  16   // change this to your relay GPIO

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // TURN ON relay
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);  // 2 seconds ON

  // TURN OFF relay
  digitalWrite(RELAY_PIN, LOW);
  delay(2000);  // 2 seconds OFF
}
