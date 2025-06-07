#include <Arduino.h>
#include "Odometry.h"
#include "Updatable.h"
#include "VelocityEncoder.h"

Odometry::Odometry(double lx, double ly, VelocityEncoder& frontLeftVelocityEncoder, VelocityEncoder& frontRightVelocityEncoder, VelocityEncoder& backLeftVelocityEncoder, VelocityEncoder& backRightVelocityEncoder) 
  : frontLeftVelocityEncoder(frontLeftVelocityEncoder),
    frontRightVelocityEncoder(frontRightVelocityEncoder),
    backLeftVelocityEncoder(backLeftVelocityEncoder),
    backRightVelocityEncoder(backRightVelocityEncoder) {
  this->lx = lx;  
  this->ly = ly;
  this->x = 0;
  this->y = 0;
  this->theta = 0;
}

double Odometry::getX() {
  return x;
}

double Odometry::getY() {
  return y;
}

double Odometry::getTheta() {
  return theta; 
}

void Odometry::update() {
  double frontLeftVelocity = frontLeftVelocityEncoder.getVelocity();
  double frontRightVelocity = frontRightVelocityEncoder.getVelocity();
  double backLeftVelocity = backLeftVelocityEncoder.getVelocity();
  double backRightVelocity = backRightVelocityEncoder.getVelocity();

  double vx = (frontLeftVelocity + frontRightVelocity + backLeftVelocity + backRightVelocity) / 4;
  double vy = (-frontLeftVelocity + frontRightVelocity + backLeftVelocity - backRightVelocity) / 4;
  double vTheta = (-frontLeftVelocity + frontRightVelocity - backLeftVelocity + backRightVelocity) / (4 * (lx + ly));

  unsigned long currentTime = millis();
  double dt = (currentTime - prevTime) / 1000.0;

  x += vx * dt;
  y += vy * dt;
  theta += vTheta * dt; 
}
