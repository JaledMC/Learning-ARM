#include <Arduino.h>
void setup() {
    pinMode(PB12, OUTPUT);
}

void loop() {
    digitalWrite(PB12, HIGH);
    delay(50);
    digitalWrite(PB12, LOW);
    delay(100);
}