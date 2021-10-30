const int mot1_pin=DO;                          
const int mot2_pin=D1;
const int mot3_pin=D2;
const int mot4_pin=D3;
const int trigpin1=D6;
const int echopin1=D7i;
int speed=200;
int TRESH = 200;
void moveBackward()
{
  //SetSpeed(90);
  digitalWrite(mot1_pin, LOW);
  digitalWrite(mot2_pin, HIGH);
  digitalWrite(mot3_pin, LOW);
  digitalWrite(mot4_pin, HIGH);
}
void moveForward()
{
    //SetSpeed(100);
  digitalWrite(mot1_pin, HIGH);
  digitalWrite(mot2_pin, LOW);
  digitalWrite(mot3_pin, HIGH);
  digitalWrite(mot4_pin, LOW);
}
void arcRight()
{
   // SetSpeed(90);

  digitalWrite(mot1_pin, HIGH);
  digitalWrite(mot2_pin, LOW);
  digitalWrite(mot3_pin, LOW);
  digitalWrite(mot4_pin, LOW);
}
void spotRight()
{
   // SetSpeed(90);

  digitalWrite(mot1_pin, HIGH);
  digitalWrite(mot2_pin, LOW);
  digitalWrite(mot3_pin, LOW);
  digitalWrite(mot4_pin, HIGH);
}

void arcLeft()
{
     // SetSpeed(90);

  digitalWrite(mot1_pin, LOW);
  digitalWrite(mot2_pin, LOW);
  digitalWrite(mot3_pin, HIGH);
  digitalWrite(mot4_pin, LOW);
}
void spotLeft()
{
      //SetSpeed(90);

  digitalWrite(mot1_pin, LOW);
  digitalWrite(mot2_pin, HIGH);
  digitalWrite(mot3_pin, HIGH);
  digitalWrite(mot4_pin, LOW);
}
void Stop()
{
  digitalWrite(mot1_pin, LOW);
  digitalWrite(mot2_pin, LOW);
  digitalWrite(mot3_pin, LOW);
  digitalWrite(mot4_pin, LOW);
}
void setup()
{
//  pinMode(3, OUTPUT);
//  pinMode(4, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
  //pinMode(6, OUTPUT);
  //pinMode(7, OUTPUT);
  //pinMode(8, OUTPUT);
   pinMode(mot1_pin,OUTPUT);
   pinMode(mot2_pin,OUTPUT);
   pinMode(mot3_pin,OUTPUT);
   pinMode(mot4_pin,OUTPUT);
    pinMode(trigpin1,OUTPUT);
   pinMode(echopin1,INPUT);
    Serial.begin(9600);
}
long duration1,distance1;
void loop()
{
  // for 1st ping .. !!
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin1,LOW);
  duration1=pulseIn(echopin1,HIGH);
  distance1=(duration1/2)/29.1;
  
  Serial.println();
  Serial.print(distance1);


   if(distance1<5)
    {
      spotLeft();
      Serial.print(" Spot left");
      delay(100);
      moveForward();
      Serial.print(" move forward ");
      
    }
    else{
    moveForward();
    Serial.print(" move forward ");
    delay(1000);
    spotRight();
    Serial.print(" Spot right");
    delay(100);
    moveForward();
    Serial.print(" move forward ");
    delay(1000);
     spotLeft();
      Serial.print(" Spot left");
      delay(100);
      moveForward();
    Serial.print(" move forward ");
    delay(1000);
    
    
}
}
