#include "Sensors.h"

// Pin Configuration
const int pingPin = 7;
const int echoPin = 6;
const int respin = A0;
const int buzzerPin = 5;
const int BUTTON_PIN = 3;

// Thresholds
const int WATER_THRESHOLD = 100;
const long DISTANCE_THRESHOLD = 75;

// State Variables
int lastState = LOW;
int currentState;
bool programEnabled = false;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  currentState = digitalRead(BUTTON_PIN);
  
  // Toggle
  if (lastState == HIGH && currentState == LOW) {
    programEnabled = !programEnabled;
    Serial.println(programEnabled ? "System Enabled" : "System Disabled");
  }
  lastState = currentState;
  
  if (programEnabled) {
    long cm = getDistanceCM(pingPin, echoPin);
    bool waterDetected = isWaterDetected(respin, WATER_THRESHOLD);
    
    // Debug output
    Serial.print("Distance: "); Serial.print(cm); Serial.println("cm");
    Serial.println(waterDetected ? "Water Alert!" : "No Water");
    
    // Trigger alarm
    if (waterDetected || (cm < DISTANCE_THRESHOLD)) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }
    
    delay(100);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}
