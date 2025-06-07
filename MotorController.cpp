#include "Arduino.h"
#include "MotorController.h"
#include "Motor.h"
#include "PIDController.h"
#include "VelocityEncoder.h"

MotorController::MotorController(Motor& motor, VelocityEncoder& velocityEncoder, PIDController& pid) 
  : motor(motor),
    pid(pid),
    velocityEncoder(velocityEncoder)
{
  this->prevUsingVelocity = false;
}

void MotorController::setVoltage(double voltage) {
  motor.setVoltage(voltage);
  prevUsingVelocity = false;
}

void MotorController::setPower(double power) {
  motor.setPower(power);
  prevUsingVelocity = false;
}

void MotorController::setVelocity(double velocity) {
  if (prevUsingVelocity == false) {
    pid.reset();
    prevUsingVelocity = true;
  }

  double voltage = pid.calculate(velocityEncoder.getVelocity(), velocity);
  motor.setVoltage(voltage);
}

void MotorController::stop() {
  motor.setVoltage(0);
}