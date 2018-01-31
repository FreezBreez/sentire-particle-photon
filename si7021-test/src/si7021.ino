// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (D1 on Photon/Electron)
// Connect SDA to I2C data pin  (D0 on Photon/Electron)


#include "Adafruit_Si7021.h"   // Use for Build IDE
// #include "Adafruit_Si7021.h"               // Use for local build

Adafruit_Si7021 temphumSensor = Adafruit_Si7021();
float humiditySi7021;
float temperatureSi7021;

void setup() {
    Serial.begin(9600);
    temphumSensor.begin();

}

void loop() {

    humiditySi7021 = temphumSensor.readHumidity();
    temperatureSi7021 = temphumSensor.readTemperature();

    Serial.printlnf("Temperature: %1.2f", temperatureSi7021);
    Serial.printlnf("Humidity: %1.2f", humiditySi7021);
    //Particle.publish("temperature", temperature, PRIVATE);

    //Particle.publish("humidity", humidity, PRIVATE);

    delay(2000);
}
