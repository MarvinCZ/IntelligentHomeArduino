/*
  Pir.cpp - interface library for pir
*/

#include "Arduino.h"
#include "Pir.h"

Pir::Pir(int pin, int initTime){
  _pin = pin;
  _initTime = initTime;
  pinMode(_pin, INPUT);
  digitalWrite(_pin, LOW);
  _initStartTime = millis();
}

bool Pir::isActive(){
  return millis() - _initStartTime >= _initTime * 1000;
}

bool Pir::getState(){
  return digitalRead(_pin);
}

int Pir::getPin(){
  return _pin;
}
