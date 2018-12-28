#include <Arduino.h>

void setup() {
    pinMode(PA0, PWM);
    pinMode(PA8, PWM);
    pinMode(PB0, PWM);
    pinMode(PB6, PWM);
    pinMode(B12, OUTPUT);

}

void loop() {
    /*int value = 65536;
    for (int i=0; i <= 80; i++) {
        pwmWrite(PA0, value);
        pwmWrite(PA8, value);
        pwmWrite(PB0, value);
        pwmWrite(PB6, value);
        value = value - 1000;
        delay(100);
    }
    for (int i=0; i <= 40; i++) {
        pwmWrite(PA0, value);
        pwmWrite(PA8, value);
        pwmWrite(PB0, value);
        pwmWrite(PB6, value);
        value = value + 1000;
        delay(100);
    }*/
    pwmWrite(PB0, 20000);

    digitalWrite(PB12, HIGH);
    delay(100);
    digitalWrite(PB12, LOW);
    delay(100);


}


