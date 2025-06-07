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

void Motor::applyVoltage(double voltage) {
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

void Motor::setVoltage(double voltage) {
  controlMode = ControlModes::VOLTAGE;
  setpoint = constrain(voltage, -maxVoltage, maxVoltage);
}

void Motor::setPower(double power) {
  controlMode = ControlModes::POWER;
  setpoint = constrain(power, -1, 1);
}

void Motor::setVelocity(double velocity) {
  controlMode = ControlModes::VELOCITY;
  setpoint = velocity;
}

void Motor::stop() {
  controlMode = ControlModes::STOPPED;
  setpoint = 0;
}

void Motor::update() {
  switch (controlMode) {
    case ControlModes::POWER: {
      double voltage = setpoint * maxVoltage;
      applyVoltage(voltage);

      break;
    }
    case ControlModes::VELOCITY: {
      if (prevControlMode != ControlModes::VELOCITY) {
        pid.reset();
      }

      double velocity = velocityEncoder.getVelocity();
      double output = pid.calculate(velocity, setpoint);    
      applyVoltage(output);

      break;
    }
    case ControlModes::VOLTAGE: {
      applyVoltage(setpoint);
      
      break;
    }
    case ControlModes::STOPPED: {
      applyVoltage(0);
      break;
    }
  }

  prevControlMode = controlMode;
}
