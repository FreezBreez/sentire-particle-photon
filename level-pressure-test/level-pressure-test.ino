const int waterlevelPin = A1;
int levelsensorValue = 0;
float Vout = 0;
float P=0;

STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));


void setup() {
    //pinMode(waterlevelPin, INPUT);

}

void loop() {
    int i = 0;
    int sum = 0;
    int offset = 0;

    for(i = 0; i < 10; i++){
        levelsensorValue = analogRead(waterlevelPin) - 512;
        sum += levelsensorValue;
    }
    offset = sum/10.0;

    //levelsensorValue = analogRead(waterlevelPin) - offset;
    levelsensorValue = analogRead(waterlevelPin);
    float voltage= levelsensorValue * (3.3 / 4095.0);
    Vout = (3.3 * levelsensorValue) / 4095.0;
    P = Vout - 2.5;
    Serial.printlnf("Pressure: %f Pa", voltage);
    delay(2000);
}
