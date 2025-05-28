#include <Arduino.h>
#include "PIDController.h"
#include "PIDConfig.h"

PIDController::PIDController(double kP, double kI, double kD) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  reset();
}

PIDController::PIDController(const PIDConfig& config) {
  this->kP = config.kP;
  this->kI = config.kI;
  this->kD = config.kD;
  reset();
}

double PIDController::calculate(double actual, double setpoint) {
  unsigned long currentTime = millis();

  double deltaTime = (currentTime - previousTime) / 1000.0;
  double error = setpoint - actual;

  double P = kP * error;
  
  integral += error * deltaTime;
  double I = kI * integral;

  double derivative = (error - previousError) / deltaTime;
  double D = kD * derivative;

  previousError = error; 
  previousTime = currentTime;

  return P + I + D;
}

void PIDController::reset() {
  this->previousError = 0;
  this->previousTime = millis();
  this->integral = 0;
}