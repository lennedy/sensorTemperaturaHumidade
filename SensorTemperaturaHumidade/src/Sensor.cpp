#include "Sensor.h"

Sensor::Sensor():dht11(DATA_PIN){
}

void Sensor::init(){
  SensorBaseMqtt::init();
}

void Sensor::metodoPublisher(){
  int temperature = 0;
  int humidity = 0;  
  
  StaticJsonDocument<300> jsonDoc;

  jsonDoc["RSSI"]     = WiFi.RSSI();
  jsonDoc["temperatura"]    = 0;
  jsonDoc["humidade"]    = 0;
  jsonDoc["erro"]     = false;
  jsonDoc["invalido"] = false;

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    jsonDoc["temperatura"] = temperature;
    jsonDoc["humidade"]    = humidity;
  }
  else{
    jsonDoc["erro"]     = true;
    jsonDoc["invalido"] = true;
  }

  String payload = "";
  serializeJson(jsonDoc, payload);

  client.publish(topic_name, payload); 
    
}