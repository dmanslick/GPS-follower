#include <Arduino.h>
#include "Drive.h"
#include "MotorController.h"

Drive::Drive(double lx, double ly, MotorController& frontLeftMotorController, MotorController& frontRightMotorController, MotorController& backLeftMotorContoller, MotorController& backRightMotorController)
  : frontLeftMotorController(frontLeftMotorController),
    frontRightMotorController(frontRightMotorController),
    backLeftMotorController(backLeftMotorController),
    backRightMotorController(backRightMotorController)
{
  this->lx = lx;
  this->ly = ly;
}
 
void Drive::setPower(double powerX, double powerY, double powerTheta) {
  frontLeftMotorController.setPower(powerY + powerX + powerTheta);
  frontRightMotorController.setPower(powerY - powerX - powerTheta);
  backLeftMotorController.setPower(powerY - powerX + powerTheta);
  backRightMotorController.setPower(powerY + powerX - powerTheta);
}

void Drive::setVelocity(double vx, double vy, double vTheta) {
  double frontLeftVelocity = vx - vy - ((lx + ly) * vTheta); 
  double frontRightVelocity = vx + vy + ((lx + ly) * vTheta); 
  double backLeftVelocity = vx + vy - ((lx + ly) * vTheta); 
  double backRightVelocity = vx - vy + ((lx + ly) * vTheta); 

  frontLeftMotorController.setVelocity(frontLeftVelocity);
  frontRightMotorController.setVelocity(frontRightVelocity);
  backLeftMotorController.setVelocity(backLeftVelocity);
  backRightMotorController.setVelocity(backRightVelocity);
}

void Drive::stop() {
  frontLeftMotorController.stop();
  frontRightMotorController.stop();
  backLeftMotorController.stop();
  backRightMotorController.stop();
}