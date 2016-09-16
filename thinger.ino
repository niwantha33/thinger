#include <ESP8266WiFi.h>
#include <ThingerSmartConfig.h>

#define USERNAME "algobel"
#define DEVICE_ID "wroomRoom"
#define DEVICE_CREDENTIAL "xxxxxxxxx" // own id

ThingerSmartConfig thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["LAMP_1"] << digitalPin(BUILTIN_LED);
  thing["LAMP_2"] << digitalPin(16);
  thing["LAMP_3"] << digitalPin(4);
  thing["LAMP_4"] << digitalPin(5);
  thing["LAMP_5"] << digitalPin(14);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());
   thing["Temp"] >> outputValue(27);
    thing["Hum"] >> outputValue("63%");

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
