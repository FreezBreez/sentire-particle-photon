// Read inveronment variables:
//
// Temperature/Humidity: SI7020 on I2C
// Light: ldr on input A0

void readLight() {
    analogValueLdr = analogRead(ldrPin);
    analogValueLdr *= 100;
    lightPercentageLdr = analogValueLdr / 2500;
    // Serial.printlnf("Light: %1.0i", analogValue);

}

void readTempHum() {
    humiditySi7021 = temphumSensor.readHumidity();
    temperatureSi7021 = temphumSensor.readTemperature();
}
