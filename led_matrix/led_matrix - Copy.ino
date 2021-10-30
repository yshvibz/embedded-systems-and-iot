#include <SoftwareSerial.h>
SoftwareSerial matrix_LED_serial(2,3);
char msg[100];
int i=0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  matrix_LED_serial.begin(9600);
  matrix_LED_serial.print(“!Hello\r”);
  matrix_LED_serial.print(249, HEX);
  delay(5000);
}

void loop()
{
  while(Serial.available())
    {
          msg[i] = Serial.read();
          i++;          
    }
    if(msg[i-1]==’\r’)
      {
          matrix_LED_serial.print(‘!’);
          matrix_LED_serial.print(msg);
          matrix_LED_serial.print(‘\r’); 
          i=0;          
      }      
  }
