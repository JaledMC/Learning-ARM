#include <Arduino.h>
HardwareTimer timer_1(1);
HardwareTimer timer_4(4);

void setup() {
    // put your setup code here, to run once:
    pinMode(PA8, PWM);
    pinMode(PB6, PWM);
    int duty = 30000;
    pwmWrite(PA8, duty);
    pwmWrite(PB6, duty);
}

void loop() {
    int time1 = 2000;
    int time2 = 4000;
    for (int i=0; i <= 4; i++){
        timer_1.setPeriod(time1);
        timer_4.setPeriod(time2);
        time1 = time1 - 500;
        time2 = time2 - 500;
        delay(2000);
   }
}