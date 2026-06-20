#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

long getDistanceCM(int pingPin, int echoPin);
bool isWaterDetected(int resPin, int threshold);

#endif
