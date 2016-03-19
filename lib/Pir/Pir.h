/*
  Pir.h - interface library for pir 
*/

#ifndef Pir_h
#define Pir_h

class Pir
{
  public:
    Pir(int pin, int initTime);
    bool isActive();
    bool getState();
    int getPin();
  private:
    int _pin;
    int _initTime;
    int _initStartTime;
};

#endif
