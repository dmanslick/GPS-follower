#ifndef Motor_H
#define Motor_H

#include <Arduino.h>
#include "PIDController.h"
#include "Updatable.h"
#include "VelocityEncoder.h"

/*
 * Represents a DC motor controlled via PWM with support for multiple control modes:
 * direct voltage, power scaling, and closed-loop velocity control via PID.
 */
class Motor : public Updatable {
  public:
    Motor(int pwmPin, int directionPin, double maxVoltage, PIDController& pid, VelocityEncoder& velocityEncoder);

    /*
     * Sets the motor to operate in VOLTAGE mode.
     * The motor will attempt to apply the specified voltage directly.
     * voltage has a range of [-maxVoltage, maxVoltage].
     */
    void setVoltage(double voltage);

    /*
     * Sets the motor to operate in POWER mode.
     * power has a range of [-1,1].
     */
    void setPower(double power);

    /*
     * Sets the motor to operate in VELOCITY mode.
     * The motor will attempt to match the desired velocity using a PID controller.
     */
    void setVelocity(double velocity);

    /*
     * Sets the motor to operate in STOPPED mode.
     * The motor will stop moving.
     */
    void stop();

    /*
     * Updates the motor.
     */
    void update() override;
  protected:

    /*
     * Applies voltage directly to the motor.
     * voltage has a range of [-maxVoltage, maxVoltage].
     */
    void applyVoltage(double voltage);

  private:  
    int pwmPin;
    int directionPin;
    PIDController& pid;
    VelocityEncoder& velocityEncoder;
    double maxVoltage;
    enum class ControlModes {
      VOLTAGE,
      POWER,
      VELOCITY,
      STOPPED
    };
    ControlModes controlMode;
    ControlModes prevControlMode;
    double setpoint;
};

#endif