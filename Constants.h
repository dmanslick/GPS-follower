#ifndef Constants_H
#define Constants_H

#include "PIDConfig.h"

// motor pwm pins
const int LeftFrontMotorPWMPin = 0;
const int LeftBackMotorPWMPin = 1;
const int RightFronttMotorPWMPin = 2;
const int RightBackMotorPWMPin = 3;

// motor direction pins
const int LeftFrontMotorDirectionPin = 0;
const int LeftBackMotorDirectionPin = 1;
const int RightFronttMotorDirectionPin = 2;
const int RightBackMotorDirectionPin = 3;

// motor max voltage
const double MotorMaxVoltage = 5;

// PID configs
const PIDConfig LeftFrontMotorPIDConfig = { 1, 1, 1 };
const PIDConfig LeftBackMotorPIDConfig = { 1, 1, 1 };
const PIDConfig RightFrontMotorPIDConfig = { 1, 1, 1 };
const PIDConfig RightBackMotorPIDConfig = { 1, 1, 1 };

// velocity encoder pwm pins
const int LeftFrontVelocityEncoderPWMPin = 0;
const int LeftBackVelocityEncoderPWMPin = 1;
const int RightFronttVelocityEncoderPWMPin = 2;
const int RightBackVelocityEncoderPWMPin = 3;

#endif