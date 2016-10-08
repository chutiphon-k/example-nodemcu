#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
  for(int i = 0;i<5;i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["sensor"] = "gps";
  root["time"] = 1351824120;
  JsonArray& data = root.createNestedArray("data");
  data.add(double_with_n_digits(48.756080, 6));
  data.add(double_with_n_digits(2.302038, 6));
  root.printTo(Serial);
  Serial.println();
  root.prettyPrintTo(Serial);
  Serial.println();

  char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  StaticJsonBuffer<200> jsonBuffer2;
  JsonObject& root2 = jsonBuffer2.parseObject(json);
  const char* sensor = root["sensor"];
  long time          = root["time"];
  double latitude    = root["data"][0];
  double longitude   = root["data"][1];
  Serial.print("Sensor : ");
  Serial.println(sensor);
}

void loop() {}
