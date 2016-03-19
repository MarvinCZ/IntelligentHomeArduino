/*
  Gas.h - library for gas sensor
*/

#ifndef Gas_h
#define Gas_h

class Gas
{
  public:
    Gas(int pin, int limit);
    bool exceeds();
    int getState();
    int getPin();
    int getLimit();
  private:
    int _pin;
    int _limit;
};

#endif
