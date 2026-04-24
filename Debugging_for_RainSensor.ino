#define WATER_A0  1
#define WATER_D0  2

void setup() {
  Serial.begin(115200);

  pinMode(WATER_D0, INPUT);

  Serial.println("WATER SENSOR DEBUG STARTED");
}

void loop() {
  int analogValue = analogRead(WATER_A0);
  int digitalValue = digitalRead(WATER_D0);

  Serial.print("A0 (Analog): ");
  Serial.print(analogValue);

  Serial.print(" | D0 (Digital): ");
  Serial.println(digitalValue);

  delay(500);
}
