#include <math.h>
#include "DriveController.h"
#include "Drive.h"
#include "Utils.h"

DriveController::DriveController(Drive& drive, PIDController& distanceController, double tolerance) : drive(drive), distanceController(distanceController) {
  this->waypointsCount = 0;
  this->currentWaypointCount = 0;
  this->tolerance = tolerance;
}

void DriveController::addWaypoint(double x, double y) {
  this->waypoints[waypointsCount][0] = x;
  this->waypoints[waypointsCount][1] = y;
  this->waypointsCount++;
}

void DriveController::run() {
  double heading = 0.0; // TODO: calculate the heading of the robot
  double desiredHeading = 0.0; // TODO: calculate the desired heading of the robot

  if ()

  if (!Utils::isApproxEqual(heading, 1, desiredHeading)) {
    drive.setLeftPower(-1);
    drive.setRightPower(1);
  } else {

  }
}