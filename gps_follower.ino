#include <PS4Controller.h>
#include <ps4.h>
#include <ps4_int.h>
#include "Drive.h"
#include "PIDController.h"
#include "Motor.h"
#include "MotorController.h"
#include "VelocityEncoder.h"
#include "Odometry.h"
#include "Constants.h"
#include "ConfigTypes.h"
#include "Updater.h"
#include "DriveController.h"

// create all motors
Motor frontLeftMotor(FrontLeftMotorPinConfig.pwmPin, FrontLeftMotorPinConfig.directionPin, MotorMaxVoltage);
Motor frontRightMotor(FrontRightMotorPinConfig.pwmPin, FrontRightMotorPinConfig.directionPin, MotorMaxVoltage);
Motor backLeftMotor(BackLeftMotorPinConfig.pwmPin, BackLeftMotorPinConfig.directionPin, MotorMaxVoltage);
Motor backRightMotor(BackRightMotorPinConfig.pwmPin, BackRightMotorPinConfig.directionPin, MotorMaxVoltage);

// create all motor PIDs
PIDController frontLeftPID(FrontLeftMotorPIDConfig.kP, FrontLeftMotorPIDConfig.kI, FrontLeftMotorPIDConfig.kD);
PIDController frontRightPID(FrontRightMotorPIDConfig.kP, FrontRightMotorPIDConfig.kI, FrontRightMotorPIDConfig.kD);
PIDController backLeftPID(BackLeftMotorPIDConfig.kP, BackLeftMotorPIDConfig.kI, BackLeftMotorPIDConfig.kD);
PIDController backRightPID(BackRightMotorPIDConfig.kP, BackRightMotorPIDConfig.kI, BackRightMotorPIDConfig.kD);

// create all velocity encoders
VelocityEncoder frontLeftVelocityEncoder(FrontLeftVelocityEncoderConfig.pinA, FrontLeftVelocityEncoderConfig.pinB, WheelRadius);
VelocityEncoder frontRightVelocityEncoder(FrontRightVelocityEncoderConfig.pinA, FrontRightVelocityEncoderConfig.pinB, WheelRadius);
VelocityEncoder backLeftVelocityEncoder(BackLeftVelocityEncoderConfig.pinA, BackLeftVelocityEncoderConfig.pinB, WheelRadius);
VelocityEncoder backRightVelocityEncoder(BackRightVelocityEncoderConfig.pinA, BackRightVelocityEncoderConfig.pinB, WheelRadius);

// create all motor controllers
MotorController frontLeftMotorController(frontLeftMotor, frontLeftVelocityEncoder, frontLeftPID);
MotorController frontRightMotorController(frontRightMotor, frontRightVelocityEncoder, frontRightPID);
MotorController backLeftMotorController(backLeftMotor, backLeftVelocityEncoder, backLeftPID);
MotorController backRightMotorController(backRightMotor, backRightVelocityEncoder, backRightPID);

// create drive
Drive drive(LX, LY, frontLeftMotorController, frontRightMotorController, backLeftMotorController, backRightMotorController);

// create odometry
Odometry odometry(LX, LY, frontLeftVelocityEncoder, frontRightVelocityEncoder, backLeftVelocityEncoder, backRightVelocityEncoder);

// create drive controller PID and drive controller
PIDController driveControllerPID(DriveControllerPIDConfig.kP, DriveControllerPIDConfig.kI, DriveControllerPIDConfig.kD);
DriveController driveController(DriveControllerConfig.xTolerance, DriveControllerConfig.yTolerance, DriveControllerConfig.thetaTolerance, drive, driveControllerPID, odometry);

// create updater
Updater updater;

// create PS4 controller
PS4Controller controller;

bool autoDrive = false;

void setup() {
  // begin all motors and velocity encoders
  frontLeftMotor.begin();
  frontRightMotor.begin();
  backLeftMotor.begin();
  backRightMotor.begin();
  frontLeftVelocityEncoder.begin();
  frontRightVelocityEncoder.begin();
  backLeftVelocityEncoder.begin();
  backRightVelocityEncoder.begin();

  // register updatables
  updater.registerUpdatable(&frontLeftVelocityEncoder);
  updater.registerUpdatable(&frontRightVelocityEncoder);
  updater.registerUpdatable(&backLeftVelocityEncoder);
  updater.registerUpdatable(&backRightVelocityEncoder);
  updater.registerUpdatable(&odometry);

  // begin the PS4 controller
  controller.begin();
}

void loop() {
  // run the updater
  updater.run();
  
  if (autoDrive == true) {
    driveController.run();
  }

  if (controller.Circle()) {
    autoDrive = !autoDrive;
  }

  if (autoDrive == false) {
    double xPower = static_cast<double>(controller.LStickX()) / 127.0;
    double yPower = static_cast<double>(controller.LStickY()) / 127.0;
    double thetaPower = static_cast<double>(controller.RStickX()) / 127.0;
    drive.setPower(xPower, yPower, thetaPower);
  }
}
