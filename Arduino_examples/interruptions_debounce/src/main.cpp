#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

volatile int uno = 0;
volatile int dos = 0;
volatile int tres = 0;
volatile int cuatro = 0;
volatile int cinco = 0;

void display() {
    lcd.setCursor(0,1);
    lcd.print("Uno:");
    lcd.print(uno);
    lcd.setCursor(10,1);
    lcd.print("Dos:");
    lcd.print(dos);
    lcd.setCursor(0,2);
    lcd.print("Tres:");
    lcd.print(tres);
    lcd.setCursor(10,2);
    lcd.print("Cuatro:");
    lcd.print(cuatro);
    lcd.setCursor(0,3);
    lcd.print("Cinco:");
    lcd.print(cinco);
    delay(50);
    lcd.clear();
}
void up() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) {
        uno++;
    }
    last_interrupt_time = interrupt_time;
}
void down() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) {
        dos++;
    }
    last_interrupt_time = interrupt_time;
}
void screen() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) {
        tres++;
    }
    last_interrupt_time = interrupt_time;
}
void select_func() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) {
        cuatro++;
    }
    last_interrupt_time = interrupt_time;
}
void run_func() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) {
        cinco++;
    }
    last_interrupt_time = interrupt_time;
}

void setup() {
    //Setup buttons
    pinMode(PA3, INPUT_PULLUP);
    pinMode(PA4, INPUT_PULLUP);
    pinMode(PB0, INPUT_PULLUP);
    pinMode(PA6, INPUT_PULLUP);
    pinMode(PA7, INPUT_PULLUP);
    pinMode(PC13, OUTPUT);
    attachInterrupt(PA3, up, RISING);
    attachInterrupt(PA4, down, RISING);
    attachInterrupt(PB0, screen, RISING);
    attachInterrupt(PA6, select_func, RISING);
    attachInterrupt(PA7, run_func, RISING);
    //Setup screen
    Wire.begin();
    lcd.begin(20,4);
    lcd.backlight();
    //Start  message
    lcd.setCursor(8,0);
    lcd.print("****");
    lcd.setCursor(4,1);
    lcd.print("SnapProject");
    lcd.setCursor(8,2);
    lcd.print("****");
    delay(2000);
    lcd.clear();
    delay(500);
}
void loop() {
    display();
}