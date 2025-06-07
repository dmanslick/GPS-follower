#include <Arduino.h>
#include "VelocityEncoder.h"

VelocityEncoder::VelocityEncoder(int pinA, int pinB, double wheelRadius) {
  this->pinA = pinA;
  this->pinB = pinB;
  this->wheelRadius =  wheelRadius;
  this->prevTime = micros();
  this->prevA = 0;
  this->velocity = 0;
}

double VelocityEncoder::getVelocity() {
  return velocity;
}

double VelocityEncoder::getAngularVelocity() {
  return velocity / 2 * PI * wheelRadius;
}

void VelocityEncoder::update() {
  int A = digitalRead(pinA);
  int B = digitalRead(pinB);

  if (A == HIGH && prevA == LOW) {
    unsigned long currentTime = micros();
    unsigned long dt = currentTime - prevTime;

    int direction = 0;

    if (A == B) {
      direction = 1;
    } else {
      direction = -1;
    }

    double pulsesPerSecond = 1000000.0 / dt;
    double pulsesPerRevolution = 44;
    double circumfrence = 2 * PI * wheelRadius; 

    velocity = (pulsesPerSecond / pulsesPerRevolution) * circumfrence * direction;

    prevTime = currentTime;
  }
  
  prevA = A;
}

void VelocityEncoder::begin() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
}