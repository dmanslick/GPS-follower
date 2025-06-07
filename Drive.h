#ifndef Drive_H
#define Drive_H

#include <Arduino.h>
#include "MotorController.h"

class Drive {
  public: 
    Drive(double lx, double ly, MotorController& frontLeftMotorController, MotorController& frontRightMotorController, MotorController& backLeftMotorContoller, MotorController& backRightMotorController);
    void setPower(double powerX, double powerY, double powerTheta);
    void setFrontLeftVelocity(double velocity);
    void setFrontRightVelocity(double velocity);
    void setBackLeftVelocity(double velocity);
    void setBackRightVelocity(double velocity);
    void setVelocity(double vx, double vy, double vTheta);
    void stop();
  private:
    MotorController frontLeftMotorController;
    MotorController frontRightMotorController;
    MotorController backLeftMotorController;
    MotorController backRightMotorController;
    double lx;
    double ly;
};

#endif
