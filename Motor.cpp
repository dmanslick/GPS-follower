#include <Arduino.h>
#include "Motor.h"
#include "PIDController.h"

Motor::Motor(int pwmPin, int directionPin, double maxVoltage, PIDController& pid, VelocityEncoder& velocityEncoder)
  : pwmPin(pwmPin),
    directionPin(directionPin),
    maxVoltage(maxVoltage),
    pid(pid),
    velocityEncoder(velocityEncoder),
    controlMode(ControlModes::POWER),
    prevControlMode(ControlModes::POWER),
    setpoint(0)
{
  pinMode(pwmPin, OUTPUT);
  digitalWrite(directionPin, HIGH);
}

void Motor::setVoltage(double voltage) {
  voltage = constrain(voltage, -maxVoltage, maxVoltage);

  int pwmValue = (int)(255.0 * (fabs(voltage) / maxVoltage));
  pwmValue = constrain(pwmValue, 0, 255);

  if (voltage < 0) {
    digitalWrite(directionPin, LOW); 
  } else {
    digitalWrite(directionPin, HIGH);
  }

  analogWrite(pwmPin, pwmValue);
}

void Motor::setPower(double power) {
  controlMode = ControlModes::POWER;
  setpoint = power;
}

void Motor::setVelocity(double velocity) {
  controlMode = ControlModes::VELOCITY;
  setpoint = velocity;
}

void Motor::update() {
  switch (controlMode) {
    case ControlModes::POWER: {
      double voltage = setpoint * maxVoltage;
      setVoltage(voltage);

      break;
    }
    case ControlModes::VELOCITY: {
      if (prevControlMode != ControlModes::VELOCITY) {
        pid.reset();
      }

      double velocity = velocityEncoder.getVelocity();
      double output = pid.calculate(velocity, setpoint);    
      setVoltage(output);

      break;
    }
  }

  prevControlMode = controlMode;
}
