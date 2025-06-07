#include "Drive.h"
#include "PIDController.h"
#include "Motor.h"
#include "MotorController.h"
#include "VelocityEncoder.h"
#include "Odometry.h"
#include "Constants.h"
#include "ConfigTypes.h"
#include "Updater.h"

// create all motors
Motor frontLeftMotor(FrontLeftMotorPinConfig.pwmPin, FrontLeftMotorPinConfig.directionPin, MotorMaxVoltage);
Motor frontRightMotor(FrontRightMotorPinConfig.pwmPin, FrontRightMotorPinConfig.directionPin, MotorMaxVoltage);
Motor backLeftMotor(BackLeftMotorPinConfig.pwmPin, BackLeftMotorPinConfig.directionPin, MotorMaxVoltage);
Motor backRightMotor(BackRightMotorPinConfig.pwmPin, BackRightMotorPinConfig.directionPin, MotorMaxVoltage);

// create all PIDs
PIDController frontLeftPID(FrontLeftMotorPIDConfig.kP, FrontLeftMotorPIDConfig.kI, FrontLeftMotorPIDConfig.kD);
PIDController frontRightPID(FrontRightMotorPIDConfig.kP, FrontRightMotorPIDConfig.kI, FrontRightMotorPIDConfig.kD);
PIDController backLeftPID(BackLeftMotorPIDConfig.kP, BackLeftMotorPIDConfig.kI, BackLeftMotorPIDConfig.kD);
PIDController backRightPID(BackRightMotorPIDConfig.kP, BackRightMotorPIDConfig.kI, BackRightMotorPIDConfig.kD);

// create all velocity encoders
VelocityEncoder frontLeftVelocityEncoder(FrontLeftVelocityEncoderConfig.pinA, FrontLeftVelocityEncoderConfig.pinB, WheelRadius);
VelocityEncoder frontRightVelocityEncoder(FrontRightVelocityEncoderConfig.pinA, FrontRightVelocityEncoderConfig.pinB, FrontRightVelocityEncoderConfig.wheelRadius);
VelocityEncoder backLeftVelocityEncoder(BackLeftVelocityEncoderConfig.pinA, BackLeftVelocityEncoderConfig.pinB, BackLeftVelocityEncoderConfig.wheelRadius);
VelocityEncoder backRightVelocityEncoder(BackRightVelocityEncoderConfig.pinA, BackRightVelocityEncoderConfig.pinB, BackRightVelocityEncoderConfig.wheelRadius);

// create all motor controllers
MotorController frontLeftMotorController(frontLeftMotor, frontLeftVelocityEncoder, frontLeftPID);
MotorController frontRightMotorController(frontRightMotor, frontRightVelocityEncoder, frontRightPID);
MotorController backLeftMotorController(backLeftMotor, backLeftVelocityEncoder, backLeftPID);
MotorController backRightMotorController(backRightMotor, backRightVelocityEncoder, backRightPID);

// create drive
Drive drive(LX, lY, frontLeftMotorController, frontRightMotorController, backLeftMotorController, backRightMotorController);

// create odometry
Odometry odometry(LX, LY, frontLeftMotorController, frontRightMotorController, backLeftMotorController, backRightMotorController);

// create updater
Updater updater;

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
  updater.registerUpdatable(frontLeftVelocityEncoder);
  updater.registerUpdatable(frontRightVelocityEncoder);
  updater.registerUpdatable(backLeftVelocityEncoder);
  updater.registerUpdatable(backRightVelocityEncoder);
  updater.registerUpdatable(odometry);
}

void loop() {
  // run the updater
  updater.run();

  // TODO: controller logic
}
