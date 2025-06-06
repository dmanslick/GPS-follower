#ifndef DriveController_H
#define DriveController_H

#include <math.h>
#include "Drive.h"
#include "Constants.h"
#include "PIDController.h"
#include "Utils.h"

class DriveController {
  public: 
    DriveController(Drive& drive, PIDController& distanceController, double tolerance)
    void run();
    void addWaypoint(double x, double y);
  private:
    double waypoints[MaxWaypoints][2];
    int waypointsCount;
    int currentWaypointCount;
    double tolerance;
    PIDController& distanceController;
    Drive& drive;
};

#endif
