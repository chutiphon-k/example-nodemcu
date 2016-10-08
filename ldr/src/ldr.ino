void setup() {
  Serial.begin(9600);
}

void loop() {
  double sensorValue = analogRead(A0);
  Serial.print("Light is: ");
  Serial.println(sensorValue);
  delay(1000);
}
