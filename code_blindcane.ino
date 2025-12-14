#include <Wire.h> 

#define trigPin 9
#define echoPin 10
#define buzzerPin 8
#define vibMotorPin 7
#define ledPin 6

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibMotorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH); // Correct function
  float distance = duration * 0.0344 / 2;  // Accurate distance in cm

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Feedback if object is near
  if (distance < 50) {
    digitalWrite(buzzerPin, HIGH);     // Audio feedback
    digitalWrite(vibMotorPin, HIGH);   // Tactile feedback
    digitalWrite(ledPin, HIGH);        // Visual feedback
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibMotorPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(500); // Delay between readings
}