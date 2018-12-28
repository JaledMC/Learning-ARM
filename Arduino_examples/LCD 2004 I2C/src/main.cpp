#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
void setup() {
  pinMode(PB12, OUTPUT);
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
  delay(2000);
  lcd.clear();
  delay(5000);
}

void display_func() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Channel 1.");
  lcd.setCursor(0,1);
  lcd.print("Ancho:");
  lcd.setCursor(0,1);
  lcd.print("Imax:");
  lcd.setCursor(0,1);
  lcd.print("Freq:");
  delay(10);
}
void loop() {
  digitalWrite(PB12, HIGH);
  delay(1000);
  digitalWrite(PB12, LOW);
  delay(1000);
}