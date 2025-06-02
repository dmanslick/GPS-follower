#ifndef ConfigTypes_H
#define ConfigTypes_H

struct PIDConfig {
  double kP;
  double kI;
  double kD;
};

struct MotorPinConfig {
  int pwmPin;
  int directionPin;
}

struct VelocityEncoderPinConfig {
  int pinA;
  int pinB;
  double wheelRadius;
}

#endif