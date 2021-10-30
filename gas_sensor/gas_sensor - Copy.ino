 
float sensorValue; //variable to store sensor value 
void setup() { 
  pinMode(A0,INPUT);
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Gas sensor warming up!"); 
  delay(20000); // allow the MQ-6 to warm up
  }
  void loop() {
    sensorValue = analogRead(A0); // read analog input pin 0
    Serial.print("Sensor Value: "); 
    Serial.print(sensorValue);
    if(sensorValue > 400)
    {
      Serial.print(" | LPG detected!"); 
      }
      Serial.println("");
      delay(2000); // wait 2s for next reading 
      }
