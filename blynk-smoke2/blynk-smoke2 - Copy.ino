#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
#define BLYNK_PRINT Serial // Comment this out to disable prints and save space 
char auth[] = "dYhpxohhHI7yIbLiWlNs906Zo7LcJi6L"; //Enter Authentication code sent by Blynk on your regested email 
char ssid[] = "realme 7i";
// Enter WIFI Name Here 
char pass[] = "divya@123"; // Enter WIFI Password Here
int mq2 = A0;

// smoke sensor is connected with the analog pin A0 #define BLYNK_TEMPLATE_ID "TMPLS-29vx9W"
#define BLYNK_DEVICE_NAME "Nithin"
int data = 0; 
int val=0;
int led=0;
int level=0;
void setup() 
{ Serial.begin(115200);
Blynk.begin(auth, ssid, pass); 
timer.setInterval(1000L, getSendData);
Blynk.notify("hey,nithin!hardware push");
}
void loop() {
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
  } void getSendData()
  {
    data = analogRead(mq2);
  val=analogRead(mq2);
    led=analogRead(mq2);
 level=analogRead(mq2);
    Blynk.virtualWrite(V2, data);
    Blynk.virtualWrite(V3, val);
    Blynk.virtualWrite(V4, led);
  Blynk.virtualWrite(V6, level);
  Blynk.virtualWrite(V5, "stop");
    if (data > 100 ) 
    { Blynk.notify("Smoke Detected!");
    }
    }
