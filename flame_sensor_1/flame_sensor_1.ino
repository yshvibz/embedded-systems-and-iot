int buzzer = 4;
int LED = 13;
int flame_sensor = 3;
int flame_detected;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
   

void loop()
{

int range = map(sensorReading, sensorMin, sensorMax, 0, 5);
 switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("* Close Fire *");
     break;
    
   
  case 1:    // A fire between 1-3 feet away.
    Serial.println("* Distant Fire *");
    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    break;
  }
}
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1)
  {
    Serial.println("Flame detected.");
    tone(buzzer,100,500);
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("no fire detected");
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
}
