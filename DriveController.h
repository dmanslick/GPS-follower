#ifndef DriveController_H
#define DriveController_H

#include <math.h>
#include "Drive.h"
#include "Constants.h"
#include "PIDController.h"
#include "Utils.h"
#include "Odometry.h"

class DriveController {
  public: 
    DriveController(double xTolerance, double yTolerance, double thetaTolerance, Drive& drive, PIDController& distanceController, Odometry& odometry);
    void run();
    void addWaypoint(double x, double y);
  private:
    double waypoints[MaxWaypoints][2];
    int waypointsCount;
    int currentWaypointCount;
    double xTolerance;
    double yTolerance;
    double thetaTolerance;
    PIDController& distanceController;
    Drive& drive;
    Odometry& odometry;
};

#endif
