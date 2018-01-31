const int ldrPin = A0;
int analogValueLdr;
float lightPercentageLdr;

void setup() {
    pinMode(ldrPin, INPUT);
}

void loop() {
    analogValueLdr = analogRead(ldrPin);
    analogValueLdr *= 100;
    lightPercentageLdr = analogValueLdr / 2500;
    // Serial.printlnf("Light: %1.0i", analogValue);
    Serial.printlnf("Light: %1.0f percent", lightPercentageLdr);
    delay(2000);
}
