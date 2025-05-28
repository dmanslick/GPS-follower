#ifndef Encoder_H
#define Endoder_H

#include <Arduino.h>
#include "Updatable.h"

class VelocityEncoder : public Updatable {
  public:
    VelocityEncoder(int port);
    void update() override;
    double getVelocity();
  private:
    int port;
}

#endif