#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;

byte a[8]=     {0x00,0xE9,0x89,0xE9,0x29,0xEF,0x00,0x00,};
byte b[8]=     {0x00,0xE7,0x94,0xE7,0x91,0xE7,0x00,0x00,};
byte c[8]=     {0x00,0xEC,0x8A,0x8C,0x8A,0xEA,0x00,0x00,};
byte d[8]=     {0x00,0xEE,0x49,0x4E,0x49,0xEE,0x00,0x00,};
byte e[8]= {0x00,0xF0,0x80,0xF0,0x80,0xF0,0x00,0x00,};


LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 

    byte f[8]=   {0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00,};
    byte g[8]= {0xFF,0x99,0x00,0x00,0x81,0xC3,0xE7,0xFF,};
    byte h[8]=   {0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00,};
    byte i[8] = {0xFF,0x99,0x00,0x00,0x81,0xC3,0xE7,0xFF,};
    
    printByte(f);
     
    delay(1000);

    printByte(g);
    
    delay(1000);

    printByte(h);    

    delay(1000);

    printByte(i);

    delay(1000);
   
    printEduc8s();
   
    lc.clearDisplay(0);
    
    delay(1000);
}

void printEduc8s()
{
  printByte(a);
  delay(1000);
  printByte(b);
  delay(1000);
  printByte(c);
  delay(1000);
  printByte(d);
  delay(1000);
  printByte(e);
  delay(1000);
  
  
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
