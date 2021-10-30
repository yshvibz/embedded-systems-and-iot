#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int buzzerPin = 12;
const int flamePin = 11;
const int ledPin = 8;
int Flame = HIGH;
void setup() {
  myservo.attach(9); 
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}

void loop() {
   Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    Serial.println("Fire!!!");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
//    digitalWrite(ledPin, LOW);
    delay(100);
   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  else
  {
    Serial.println("No worries");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    
    delay(100);
  }
  
}
