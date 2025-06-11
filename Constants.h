#ifndef Constants_H
#define Constants_H

#include "ConfigTypes.h"

// motor pin configs
const MotorPinConfig FrontLeftMotorPinConfig = { 0, 0 };
const MotorPinConfig FrontRightMotorPinConfig = { 0, 0 };
const MotorPinConfig BackLeftMotorPinConfig = { 0, 0 };
const MotorPinConfig BackRightMotorPinConfig = { 0, 0 };

// motor max voltage
const double MotorMaxVoltage = 5;

// wheel radius
const double WheelRadius = 1;

// PID configs
const PIDConfig FrontLeftMotorPIDConfig = { 1, 1, 1 };
const PIDConfig FrontRightMotorPIDConfig = { 1, 1, 1 };
const PIDConfig BackLeftMotorPIDConfig = { 1, 1, 1 };
const PIDConfig BackRightMotorPIDConfig = { 1, 1, 1 };
const PIDConfig DriveControllerPIDConfig = { 1, 1, 1 };

// velocity encoder configs
const VelocityEncoderConfig FrontLeftVelocityEncoderPinConfig = { 0, 0 };
const VelocityEncoderConfig FrontRightVelocityEncoderPinConfig = { 0, 0 };
const VelocityEncoderConfig BackLeftVelocityEncoderPinConfig = { 0, 0 };
const VelocityEncoderConfig BackRightVelocityEncoderPinConfig = { 0, 0 };
 
// max waypoints
const int MaxWaypoints = 100;

// drive controller config
const DriveControllerToleranceConfig DriveControllerConfig = { 1, 1, 1 };

// lx and ly
const double LX = 1;
const double LY = 1;

#endif