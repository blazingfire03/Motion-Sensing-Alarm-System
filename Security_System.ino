int led =13;                 // the pin that the LED is atteched to
int sensor = 3;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int buzz=12;
void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  //Serial.print("starting ");
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(buzz, HIGH);
    digitalWrite(led, HIGH);   // turn buzzer ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }9
  } 
  else {
      myservo.write(180);
     digitalWrite(buzz, LOW); // turn buzzer OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
