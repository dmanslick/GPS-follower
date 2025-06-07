#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int pwmPin, int directionPin, double maxVoltage) {
  this->pwmPin = pwmPin;
  this->directionPin = directionPin;
  this->maxVoltage = maxVoltage;
}

void Motor::applyVoltage(double voltage) {
  voltage = constrain(voltage, -maxVoltage, maxVoltage);

  int pwmValue = (int)(255.0 * (fabs(voltage) / maxVoltage));
  pwmValue = constrain(pwmValue, 0, 255);

  if (voltage < 0) {
    digitalWrite(directionPin, LOW); 
  } else {
    digitalWrite(directionPin, HIGH);
  }

  analogWrite(pwmPin, pwmValue);
}

void Motor::setVoltage(double voltage) {
  voltage = constrain(voltage, -maxVoltage, maxVoltage);
  applyVoltage(voltage);
}

void Motor::setPower(double power) {
  power = constrain(power, -1, 1);
  applyVoltage(maxVoltage * power);
}

void Motor::stop() {
  setVoltage(0);
}

void Motor::begin() {
  pinMode(pwmPin, OUTPUT);
  digitalWrite(directionPin, HIGH);
}
