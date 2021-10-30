const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
int buzzer=13;
int flame_sensor = 3;
int flame_detected;

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
  pinMode(flame_sensor, INPUT);
}
void loop() {
  // read the sensor on analog A0:
  int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 5);
    // range value:
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

  delay(1); 
  if(range<1)
  {
    tone(13,1000);
    delay(100);
    }// delay between reads
}
