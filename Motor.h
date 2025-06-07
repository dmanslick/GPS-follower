#ifndef Motor_H
#define Motor_H

#include <Arduino.h>

/*
 * Represents a DC motor controlled via PWM with support for multiple control modes:
 * direct voltage, power scaling, and closed-loop velocity control via PID.
 */
class Motor {
  public:
    Motor(int pwmPin, int directionPin, double maxVoltage);

    /*
     * The motor will attempt to apply the specified voltage directly.
     * voltage has a range of [-maxVoltage, maxVoltage].
     */
    void setVoltage(double voltage);

    /*
     * The motor will attempt to apply the specified power as the maxVoltage * power.
     * power has a range of [-1,1].
     */
    void setPower(double power);

    /*
     * Sets the motor to operate in STOPPED mode.
     * The motor will stop moving.
     */
    void stop();

      /*
     * Initialize pins
     */
    void begin();

  protected: 
    /*
     * Applies voltage directly to the motor.
     * voltage has a range of [-maxVoltage, maxVoltage].
     */
    void applyVoltage(double voltage);

  private:  
    int pwmPin;
    int directionPin;
    double maxVoltage;
};

#endif