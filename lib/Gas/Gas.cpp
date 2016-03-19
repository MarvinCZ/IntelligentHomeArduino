/*
  Gas.cpp - library for gas sensor
*/

#include "Arduino.h"
#include "Gas.h"

Gas::Gas(int pin, int limit){
  _pin = pin;
  _limit = limit;
}

bool Gas::exceeds(){
  return analogRead(_pin) > _limit;
}

int Gas::getState(){
  return analogRead(_pin);
}

int Gas::getPin(){
  return _pin;
}

int Gas::getLimit(){
  return _limit;
}