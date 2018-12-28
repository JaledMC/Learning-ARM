#include <Arduino.h>

void setup() {
    pinMode(PA0, OUTPUT);
    pinMode(PA1, OUTPUT);
    pinMode(PA2, OUTPUT);
    pinMode(PA3, OUTPUT);
    pinMode(PA4, OUTPUT);
}

void loop() {
    int time = 100;
    digitalWrite(PA4, LOW);
    digitalWrite(PA0, HIGH);
    delay(time);
    digitalWrite(PA0, LOW);
    digitalWrite(PA1, HIGH);
    delay(time);
    digitalWrite(PA1, LOW);
    digitalWrite(PA2, HIGH);
    delay(time);
    digitalWrite(PA2, LOW);
    digitalWrite(PA3, HIGH);
    delay(time);
    digitalWrite(PA3, LOW);
    digitalWrite(PA4, HIGH);
    delay(time);
}
