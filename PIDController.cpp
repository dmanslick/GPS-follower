#include <Arduino.h>
#include "PIDController.h"
#include "PIDConfig.h"

PIDController::PIDController(double kP, double kI, double kD) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  reset();
}

double PIDController::calculate(double actual, double setpoint) {
  unsigned long currentTime = millis();

  double dt = (currentTime - prevTime) / 1000.0;
  double error = setpoint - actual;

  double P = kP * error;
  
  integral += error * dt;
  double I = kI * integral;

  double derivative = (error - prevError) / dt;
  double D = kD * derivative;

  prevError = error; 
  prevTime = currentTime;

  return P + I + D;
}

void PIDController::reset() {
  this->prevError = 0;
  this->prevTime = millis();
  this->integral = 0;
}