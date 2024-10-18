#ifndef SENSOR_H
#define SENSOR_H

#include "SensorBaseMqtt.h"
#include <ArduinoJson.h>
#include <DHT11.h>

#define DATA_PIN 14

class Sensor: public SensorBaseMqtt {
  private:
  DHT11 dht11;

  public:
  Sensor();
  void metodoPublisher();
  void init();

};

#endif