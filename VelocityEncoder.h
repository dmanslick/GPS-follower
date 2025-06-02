#ifndef Encoder_H
#define Endoder_H

#include <Arduino.h>
#include "Updatable.h"

class VelocityEncoder : public Updatable {
  public:
    VelocityEncoder(int pinA, int pinB);
    void update() override;
    
    // velocity in m/s
    double getVelocity();
  private:
    int pinA;
    int pinB;
    int prevA;
    double wheelRadius;
    unsigned long prevTime;
    double velocity;
}

#endif