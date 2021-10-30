#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
#define BLYNK_PRINT Serial // Comment this out to disable prints and save space 
char auth[] = "dYhpxohhHI7yIbLiWlNs906Zo7LcJi6L"; //Enter Authentication code sent by Blynk on your regested email 
char ssid[] = "realme 7i";
// Enter WIFI Name Here 
char pass[] = "divya@123"; // Enter WIFI Password Here
int mq2 = A0; 
int data = 0; 
void setup() 
{ Serial.begin(115200);
Blynk.begin(auth, ssid, pass); 
timer.setInterval(1000L, getSendData);
}
void loop() {
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
  } void getSendData()
  {
    data = analogRead(mq2);
    Blynk.virtualWrite(V2, data);
    if (data > 200 ) 
    { Blynk.notify("Smoke Detected!");
    }
    }
