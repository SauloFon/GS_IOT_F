#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

const int DHT_PIN = 23;
const int TRIG_PIN = 27;
const int ECHO_PIN = 26;

DHTesp dhtSensor;

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient WOKWI_Client;
PubSubClient client(WOKWI_Client);

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("WOKWI_Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);       
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  pinMode(27,OUTPUT);
  pinMode(26, INPUT);
  
}

void Distancia(){
  int distancia = 0;
  for (;;){
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    unsigned long ts = pulseIn(ECHO_PIN,HIGH);
    distancia = ts/58;
    delay(1000);
    Serial.println(distancia);
  client.publish("WOKWI_DIST", String(distancia).c_str());}
}

void Wifi_Ok(){
  if (WiFi.status())
  digitalWrite(2, HIGH);
  else
  digitalWrite(2, LOW);
}

void Mosquitto_Ok(){
  if(client.connected())
  digitalWrite(15, HIGH);
  else
  digitalWrite(15, LOW);
}

void DHT_Envia() 
{
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  client.publish("WOKWI_DHT",String(data.temperature).c_str());
  delay(1500); 
}

void loop() {
    reconnect();
    Mosquitto_Ok();
    Wifi_Ok();
    DHT_Envia();
    Distancia();
}