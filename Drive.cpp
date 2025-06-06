#include <Arduino.h>
#include "Drive.h"
#include "Motor.h"
#include "Updatable.h"

Drive::Drive(Motor& frontLeftMotor, Motor& frontRightMotor, Motor& backLeftMotor, Motor& backRightMotor)
  : frontLeftMotor(frontLeftMotor),
    frontRightMotor(frontRightMotor),
    backLeftMotor(backLeftMotor),
    backRightMotor(backRightMotor) {
}
 
void Drive::setLeftPower(double power) {
  frontLeftMotor.setPower(power);
  backLeftMotor.setPower(power);
}

void Drive::setRightPower(double power) {
  frontRightMotor.setPower(power);
  backRightMotor.setPower(power);
}

void Drive::setPower(double powerX, double powerY, double powerTheta) {
  frontLeftMotor.setPower(powerY + powerX + powerTheta);
  frontRightMotor.setPower(powerY - powerX - powerTheta);
  backLeftMotor.setPower(powerY - powerX + powerTheta);
  backRightMotor.setPower(powerY + powerX - powerTheta);
}

void Drive::setLeftVelocity(double velocity) {
  frontLeftMotor.setVelocity(velocity);
  backLeftMotor.setVelocity(velocity);
}

void Drive::setRightVelocity(double velocity) {
  frontRightMotor.setVelocity(velocity);
  backRightMotor.setVelocity(velocity);
}

void Drive::setVelocity(double velocityFrontLeft, double velocityFrontRight, double velocityBackLeft, double velocityBackRight) {
  frontLeftMotor.setVelocity(velocityFrontLeft);
  frontRightMotor.setVelocity(velocityFrontRight);
  backLeftMotor.setVelocity(velocityBackLeft);
  backRightMotor.setVelocity(velocityBackRight);
}

void Drive::setVelocity(double vx, double vy, double vTheta) {

}