#include <SimpleDHT.h>

//Interface the DHT11 Temp & Humidity sensor and display humidity and temperature
//in Celsius on a 16x2 character LCD


#include <LiquidCrystal.h>

SimpleDHT DHT;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //set Uno pins that are connected to LCD, 4-bit mode

void setup() {
  lcd.begin(16,2);    //set 16 columns and 2 rows of 16x2 LCD

}

void loop() {
  int readDHT = DHT.read11(8);    //grab 40-bit data packet from DHT sensor
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  //lcd.print((char)223);         //used to display degree symbol on display
  //lcd.write(0xdf);              //another way to display degree symbol
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(3000);

}
