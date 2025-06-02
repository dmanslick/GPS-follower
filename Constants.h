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

// PID configs
const PIDConfig LeftFrontMotorPIDConfig = { 1, 1, 1 };
const PIDConfig LeftBackMotorPIDConfig = { 1, 1, 1 };
const PIDConfig RightFrontMotorPIDConfig = { 1, 1, 1 };
const PIDConfig RightBackMotorPIDConfig = { 1, 1, 1 };

// velocity encoder pin configs
const VelocityEncoderPinConfig LeftFrontVelocityEncoderPinConfig = { 0, 0 };
const VelocityEncoderPinConfig LeftBackVelocityEncoderPinConfig = { 0, 0 };
const VelocityEncoderPinConfig RightFronttVelocityEncoderPinConfig = { 0, 0 };
const VelocityEncoderPinConfig RightBackVelocityEncoderPinConfig = { 0, 0 };
 

#endif