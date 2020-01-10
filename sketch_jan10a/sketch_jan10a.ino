#include "HX711.h"
#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602
#include <dht11.h> // подключаем библиотеку для DHT11
#define DHT11PIN 2 // сигнал DHT11 подключаем к 2-му цифровому выводу

float side;
LiquidCrystal_I2C lcd(0x3F,20,4); 
 
dht11 DHT11;


#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "../generic/common.h"

#define PIN_WIRE_SDA (4)
#define PIN_WIRE_SCL (5)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

static const uint8_t LED_BUILTIN = 16;
static const uint8_t BUILTIN_LED = 16;

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;

#endif /* Pins_Arduino_h */

const int keysPin[4] = {
  16,5,4,0
};
const int dataPin[4] = {
  14,12,13,15
};
static const int pot[2] = {
  3,1
};
char **comm = new char*[4];
namespace request{
  void dht();
  void net();
  void loadSD();
  void chooser();
}
namespace out{
  void lcdd(){
    
  int chk = DHT11.read(DHT11PIN);
  lcd.setCursor(0, 0);
  lcd.print("Temp:    "); 
  lcd.print((float)DHT11.temperature, 2);
  lcd.print(" \1C ");

  lcd.setCursor(0, 1);
  lcd.print("Weight:    "); 
  lcd.print(side);
  lcd.print(" KG ");
  delay(1000);

    
  }
  void net();
  void saveSD();
  void relay();
}
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 4; i++)
    comm[i] = new char;
 lcd.begin (20,4);
//  dht.begin();
  lcd.createChar(1, 1);
  lcd.init();
  lcd.backlight(); 
}
void loop() {
  // put your main code here, to run repeatedly:

}
