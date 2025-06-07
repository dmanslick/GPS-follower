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

struct VelocityEncoderConfig {
  int pinA;
  int pinB;
  double wheelRadius;
}

struct DriveControllerToleranceConfig {
  double xTolerance;
  double yTolerance;
  double thetaTolerance;
}

#endif