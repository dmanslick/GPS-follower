#ifndef Motor_H
#define Motor_H

#include <Arduino.h>
#include "PIDController.h"
#include "Updatable.h"
#include "VelocityEncoder.h"

class Motor : public Updatable {
  public:
    Motor(int pwmPin, int directionPin, double maxVoltage, PIDController& pid, VelocityEncoder& velocityEncoder);
    void setPower(double power);
    void setVelocity(double velocity);
    void update() override;
  protected:
    void setVoltage(double voltage);
  private:  
    int pwmPin;
    int directionPin;
    PIDController& pid;
    VelocityEncoder& velocityEncoder;
    double maxVoltage;
    enum class ControlModes {
      POWER,
      VELOCITY
    };
    ControlModes controlMode;
    ControlModes prevControlMode;
    double setpoint;
};

#endif