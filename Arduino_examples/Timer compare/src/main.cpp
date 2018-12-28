#include <Arduino.h>
#define LED_RATE 500000    // in microseconds; should give 0.5Hz toggles

// We'll use timer 2
HardwareTimer timer(2);
volatile bool led = true;
void handler_led(void) {
    led = !led;
    digitalWrite(PC13, led);
}

void setup() {
    // Set up the LED to blink
    pinMode(PC13, OUTPUT);

    // Pause the timer while we're configuring it
    timer.pause();

    // Set up period
    timer.setPeriod(LED_RATE); // in microseconds

    // Set up an interrupt on channel 1
    timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    timer.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
    timer.attachCompare1Interrupt(handler_led);

    // Refresh the timer's count, prescale, and overflow
    timer.refresh();

    // Start the timer counting
    timer.resume();
}

void loop() {
    // Nothing! It's all in the handler_led() interrupt:
}