#ifndef Odometry_H
#define Odometry_H

#include <Arduino.h>
#include "Updatable.h"
#include "VelocityEncoder.h"

class Odometry : public Updatable {
  public: 
    Odometry(double lx, double ly, VelocityEncoder& frontLeftVelocityEncoder, VelocityEncoder& frontRightVelocityEncoder, VelocityEncoder& backLeftVelocityEncoder, VelocityEncoder& backRightVelocityEncoder);
    double getX();
    double getY();
    double getTheta();
    void update() override;
  private:  
    double lx; 
    double ly;
    VelocityEncoder frontLeftVelocityEncoder;
    VelocityEncoder frontRightVelocityEncoder;
    VelocityEncoder backLeftVelocityEncoder;
    VelocityEncoder backRightVelocityEncoder;
    double x;
    double y;
    double theta;
    unsigned long prevTime;
};

#endif