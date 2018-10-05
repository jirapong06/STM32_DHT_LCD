#include "DHT.h"

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN PB5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  
  dht.begin();
  
  lcd.print("Hello, world!");
  delay(2000);
  lcd.clear();
  lcd.print("I am ARM STM32");
  delay(2000);
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp ");
  lcd.print(temperature, 1);
  lcd.print(" *C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity ");
  lcd.print(humidity, 1);
  lcd.print(" %");
  delay(5000);
}
