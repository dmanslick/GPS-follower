#ifndef PIDController_H
#define PIDController_H

#include <Arduino.h>
#include "ConfigTypes.h"

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
      double prevError;
      double integral;
      unsigned long prevTime;
};

#endif