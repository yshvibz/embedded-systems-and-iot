#include <Servo.h>   //servo library
Servo servo;    
int trigPin = 2;    
int echoPin = 3;  
int servoPin = 9;

long duration, dist, average;  
long aver[3];   //array for average


void setup() {      
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on
    delay(1000);
    servo.detach();
}

void measure() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() {
  for (int i=0;i<=2;i++) {   //average distance
    measure();              
   aver[i]=dist;            
    delay(50);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    //average distance by 3 measurements

if ( dist<30 ) {
 //if hand on the distance 10...30 cm
 servo.attach(servoPin);
  delay(1);
 servo.write(90);  
 delay(5000);       //wait 5 seconds
 servo.write(0);    
 delay(1000);
// servo.detach();      
}
}
