#ifndef Drive_H
#define Drive_H

#include <Arduino.h>
#include "Motor.h"
#include "Updatable.h"

class Drive : public Updatable {
  public: 
    Drive(Motor& frontLeftMotor, Motor& frontRightMotor, Motor& backLeftMotor, Motor& backRightMotor);
    void setLeftPower(double power);
    void setRightPower(double power);
    void setLeftVelocity(double velocity);
    void setRightVelocity(double velocity);
    void update() override;
  private:
    Motor& frontLeftMotor;
    Motor& frontRightMotor;
    Motor& backLeftMotor;
    Motor& backRightMotor;
};

#endif
