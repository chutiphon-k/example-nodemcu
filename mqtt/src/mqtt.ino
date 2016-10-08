#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "bach1";
const char* password = "aaaaaaaaaa";

#define mqtt_server "m13.cloudmqtt.com"
#define mqtt_port 15174
#define mqtt_user "TEST"
#define mqtt_password "12345"

#define LED_PIN 4

WiFiClient espClient;
PubSubClient client(espClient);

void setup(){
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop(){
  if(!client.connected()){
    Serial.print("Attemping MQTT connecting...");
    if(client.connect("ESP8266Client2", mqtt_user, mqtt_password)){
      Serial.println("connected");
      client.subscribe("/ESP/LED");
    } else{
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
  client.loop();
}

void callback(char* topic, byte* payload, uint length){
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String msg = "";
  int i = 0;
  while (i<length) msg += (char)payload[i++];
  if(msg == "GET"){
    client.publish("/ESP/LED", (digitalRead(LED_PIN) ? "LEDON" : "LEDOFF"));
    Serial.println("Send !");
    return;
  }
  digitalWrite(LED_PIN, (msg == "LEDON" ? HIGH : LOW));
  Serial.println(msg);
}
