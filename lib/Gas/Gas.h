/*
  Gas.h - library for gas sensor
*/

#ifndef Gas_h
#define Gas_h

class Gas
{
  public:
    Gas(int pin);
    int getValue();
    int getPin();
    bool isActive();
    void setActive(bool active);
  private:
    int _pin;
    int _active;
};

#endif
