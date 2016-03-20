/*
  Pir.h - interface library for pir 
*/

#ifndef Pir_h
#define Pir_h

class Pir
{
  public:
    Pir(int pin);
    bool isActive();
    bool getState();
    int getPin();
    void setActive(bool active);
  private:
    int _pin;
    bool _active;
};

#endif
