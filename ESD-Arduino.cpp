
int distance = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  distance = 60;
  // Distance in cm
  cm = 0.01723 * readUltrasonicDistance(6, 7);
  Serial.print(cm);
  Serial.println("cm");
  // Distance more than 60 cm
  if (cm > distance) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
  } else {
    // Distance between 60 cm and 40cm
    if (cm > 40) {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
    } else {
      // Distance between 15 cm and 40cm
      if (cm > 15) {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
      } else {
        // Distance between 15cm and 1cm
        if (cm > 1) {
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
        } else {
          // Distance below 1cm
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
        }
      }
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}