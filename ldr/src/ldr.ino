void setup() {
  Serial.begin(115200);
}

void loop() {
  double sensorValue = analogRead(A0);
  Serial.print("Light is: ");
  Serial.println(sensorValue);
  delay(1000);
}
