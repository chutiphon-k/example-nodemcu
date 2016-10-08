
#define LED LED_BUILTIN

void setup(){
  delay(5000);
  Serial.begin(115200);
  for(int i = 3;i>0;i--){
    Serial.print("Ready ");
    Serial.println(i);
    delay(1000);
  }
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(LED, 1);
  delay(1000);
  digitalWrite(LED, 0);
  delay(1000);
}
