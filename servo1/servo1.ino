#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
Servo servo;
char auth[] = "4j4aE9nBTXgAcbDhqRnPf0_ftSTnNupx";//Enter your Blynk auth token
char ssid[] = "realme 7i";//Enter your WIFI name
char pass[] = "divya@123";//Enter your WIFI password
 
BLYNK_WRITE(V0){
  servo.write(param.asInt());
}
void setup() {
  Serial.begin(9600);
  servo.attach(D1);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() {
  Blynk.run();
}
