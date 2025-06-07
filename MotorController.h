#ifndef MotorController_H
#define MotorController_H

#include <Arduino.h>
#include "PIDController.h"
#include "Motor.h"
#include "VelocityEncoder.h"

class MotorController {
  public:
    MotorController(Motor& motor, VelocityEncoder& VelocityEncoder, PIDController& pid);
    void setVoltage(double voltage);
    void setPower(double power);
    void setVelocity(double velocity);
    void stop();
  private:
    Motor motor;
    VelocityEncoder velocityEncoder;
    PIDController pid;
    bool prevUsingVelocity;
};

#endif