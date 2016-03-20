/*
  Gas.cpp - library for gas sensor
*/

#include "Arduino.h"
#include "Gas.h"

Gas::Gas(int pin){
  _pin = pin;
  _active = false;
}

int Gas::getValue(){
  return analogRead(_pin);
}

int Gas::getPin(){
  return _pin;
}

bool Gas::isActive(){
  return _active;
}

void Gas::setActive(bool active){
  _active = active;
}