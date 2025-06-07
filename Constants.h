#ifndef Constants_H
#define Constants_H

#include "ConfigTypes.h"

// motor pin configs
const MotorPinConfig LeftFrontMotorPinConfig = { 0, 0 };
const MotorPinConfig LeftBackMotorPinConfig = { 0, 0 };
const MotorPinConfig RightFronttMotorPinConfig = { 0, 0 };
const MotorPinConfig RightBackMotorPinConfig = { 0, 0 };

// motor max voltage
const double MotorMaxVoltage = 5;

// wheel radius
const double WheelRadius = 1;

// PID configs
const PIDConfig LeftFrontMotorPIDConfig = { 1, 1, 1 };
const PIDConfig LeftBackMotorPIDConfig = { 1, 1, 1 };
const PIDConfig RightFrontMotorPIDConfig = { 1, 1, 1 };
const PIDConfig RightBackMotorPIDConfig = { 1, 1, 1 };

// velocity encoder configs
const VelocityEncoderConfig LeftFrontVelocityEncoderConfig = { 0, 0, WheelRadius };
const VelocityEncoderConfig LeftBackVelocityEncoderConfig = { 0, 0, WheelRadius };
const VelocityEncoderConfig RightFronttVelocityEncoderConfig = { 0, 0, WheelRadius };
const VelocityEncoderConfig RightBackVelocityEncoderConfig = { 0, 0, WheelRadius };
 
// max waypoints
const int MaxWaypoints = 100;

// drive controller config
const DriveControllerToleranceConfig DriveControllerConfig = { 1, 1, 1 };

#endif