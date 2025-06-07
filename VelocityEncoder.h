#ifndef Encoder_H
#define Endoder_H

#include <Arduino.h>
#include "Updatable.h"

class VelocityEncoder : public Updatable {
  public:
    VelocityEncoder(int pinA, int pinB, double wheelRadius);
    void update() override;
    
    /*
     * Gets the estimated linear velocity of the encoder in m/s
     */
    double getVelocity();

    /*
     * Gets the estimated angular velocity of the encoder in rad/s
     */
    double getAngularVelocity();
  private:
    int pinA;
    int pinB;
    int prevA;
    double wheelRadius;
    unsigned long prevTime;
    double velocity;
}

#endif