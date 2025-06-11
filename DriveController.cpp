#include <math.h>
#include "DriveController.h"
#include "Drive.h"
#include "Utils.h"

DriveController::DriveController(double xTolerance, double yTolerance, double thetaTolerance, Drive& drive, PIDController& distanceController, Odometry& odometry) : drive(drive), distanceController(distanceController), odometry(odometry) {
  this->waypointsCount = 0;
  this->currentWaypointCount = 0;
  this->xTolerance = xTolerance;
  this->yTolerance = yTolerance;
  this->thetaTolerance = thetaTolerance;
}

void DriveController::addWaypoint(double x, double y) {
  this->waypoints[waypointsCount][0] = x;
  this->waypoints[waypointsCount][1] = y;
  this->waypointsCount++;
}

void DriveController::run() {
  double heading = 0.0; // TODO: calculate the heading of the robot
  double desiredHeading = 0.0; // TODO: calculate the desired heading of the robot
}