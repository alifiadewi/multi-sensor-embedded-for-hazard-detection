#include "Sensors.h"

// Calculates distance
long getDistanceCM(int pingPin, int echoPin) {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  pinMode(echoPin, INPUT);
  long duration = pulseIn(echoPin, HIGH);
  
  // Convert ms to cm
  return duration / 29 / 2;
}

bool isWaterDetected(int resPin, int threshold) {
  int resval = analogRead(resPin);
  return (resval > threshold);
}
