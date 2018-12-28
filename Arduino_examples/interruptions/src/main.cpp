#include <Arduino.h>

volatile int led1 = LOW;
volatile int led2 = LOW;
volatile int led3 = LOW;

void change_button1() {
    led1 = !led1;
}
void change_button2() {
    led2 = !led2;
}
void change_button3() {
    led3 = !led3;
}
void setup() {
    pinMode(PA0, OUTPUT);
    pinMode(PA1, OUTPUT);
    pinMode(PA2, OUTPUT);
    pinMode(PB1, INPUT);
    pinMode(PB0, INPUT);
    pinMode(PA7, INPUT);
    attachInterrupt(PB1, change_button1, CHANGE);
    attachInterrupt(PB0, change_button2, CHANGE);
    attachInterrupt(PA7, change_button3, CHANGE);
}

void loop() {
    digitalWrite(PA0, led1);
    digitalWrite(PA1, led2);
    digitalWrite(PA2, led3);
}