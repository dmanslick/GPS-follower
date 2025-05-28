#ifndef PIDController_H
#define PIDController_H

#include <Arduino.h>
#include "PIDConfig.h"

class PIDController {
  public:
    PIDController(double kP, double kI, double kD);
    PIDController(PIDConfig& config);
    double calculate(double actual, double setpoint);
    void reset();
  private: 
      double kP;
      double kI;
      double kD;
      double previousError;
      double integral;
      unsigned long previousTime;
};

#endif