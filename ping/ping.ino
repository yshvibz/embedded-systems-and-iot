#include <Servo.h>
Servo myservo;
const int trigPin = 9; 
const int echoPin = 10;// defining variables
long duration; 
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
  pinMode(3, OUTPUT);pinMode(4, OUTPUT);pinMode(5, INPUT);pinMode(11, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(6);
  } 
  void loop() { 
    // Clears the trigPin 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH); // Calculating the distance
    distance= duration*0.034/2; // Prints the distance on the Serial Monitor 
    Serial.print("Distance: "); 
    Serial.println(distance); 
    delay(100);
     int b=digitalRead(5);
    if(distance<=10){
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
     
    }
    else if(distance>10&&distance<100){
      digitalWrite(3,HIGH);
      delay(100);
       digitalWrite(3,LOW);//red
      delay(100);
      tone(11,1000,200);
      }
    else if(b==0){
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      for(int pos=0;pos<=180;pos++)
      {
      myservo.write(pos);
      delay(15);
      }
      for(int pos=180;pos>=0;pos--)
      {
      myservo.write(pos);
      delay(15);
      }
     
  }
  
      else{
     digitalWrite(4,HIGH);// green
      delay(100);
       digitalWrite(4,LOW);
      delay(100);
      }
 




    
    }
