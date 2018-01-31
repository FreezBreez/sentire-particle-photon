// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_Si7021.h>

#include <blynk.h>

const int ldrPin = A1;
int analogValueLdr;
float lightPercentageLdr;

Adafruit_Si7021 temphumSensor = Adafruit_Si7021();
float humiditySi7021;
float temperatureSi7021;

#include "callibration.h"
#include "relays.h"
#include "eeprom.h"
#include "sysReadings.h"
#include "envReadings.h"

char blynkAuth[] = "[Put your Blynk authorisation code here]"; // Blynk authorisation


void setup() {
    Blynk.begin(blynkAuth);
    pinMode(ldrPin, INPUT);
    temphumSensor.begin();
}

void loop() {
    Blynk.run();
    readTempHum();
    readLight();
    Serial.printlnf("Light: %1.0f percent", lightPercentageLdr);
    Serial.printlnf("Temperature: %1.2f degrees Celsius", temperatureSi7021);
    Serial.printlnf("Humidity: %1.2f percent", humiditySi7021);
    delay(2000);
}
