#define WATER_A0  1
#define WATER_D0  2

int threshold = 2500; // adjust after testing

void setup() {
  Serial.begin(115200);

  pinMode(WATER_D0, INPUT);

  Serial.println("WATER SENSOR READY");
}

void loop() {
  int analogValue = analogRead(WATER_A0);
  int digitalValue = digitalRead(WATER_D0);

  String status;

  // DIGITAL override (fast detection)
  if (digitalValue == LOW) {
    status = "🔴 WATER DETECTED (D0)";
  }
  else {
    // ANALOG classification
    if (analogValue > 3000) {
      status = "🟢 DRY";
    }
    else if (analogValue > 2000) {
      status = "🟡 MOIST";
    }
    else {
      status = "🔴 WET / WATER PRESENT";
    }
  }

  Serial.print("A0: ");
  Serial.print(analogValue);
  Serial.print(" | D0: ");
  Serial.print(digitalValue);
  Serial.print(" | STATUS: ");
  Serial.println(status);

  delay(500);
}
