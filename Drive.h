#ifndef Drive_H
#define Drive_H

#include <Arduino.h>
#include "Motor.h"

class Drive : public Updatable {
  public: 
    Drive(double lx, double ly, Motor& frontLeftMotor, Motor& frontRightMotor, Motor& backLeftMotor, Motor& backRightMotor);
    void setLeftPower(double power);
    void setRightPower(double power);
    void setPower(double powerX, double powerY, double powerTheta);
    void setLeftVelocity(double velocity);
    void setRightVelocity(double velocity);
    void setVelocity(double velocityFrontLeft, double velocityFrontRight, double velocityBackLeft, double velocityBackRight);
    void setVelocity(double vx, double vy, double vTheta);
    void stop();
  private:
    Motor& frontLeftMotor;
    Motor& frontRightMotor;
    Motor& backLeftMotor;
    Motor& backRightMotor;
    double lx;
    double ly;
};

#endif
