/*
  Pir.cpp - interface library for pir
*/

#include "Arduino.h"
#include "Pir.h"

Pir::Pir(int pin){
  _pin = pin;
  _active = false;
  pinMode(_pin, INPUT);
  digitalWrite(_pin, LOW);
}

bool Pir::isActive(){
  return _active;
}

bool Pir::getState(){
  return digitalRead(_pin);
}

int Pir::getPin(){
  return _pin;
}

void Pir::setActive(bool active){
  _active = active;
}
