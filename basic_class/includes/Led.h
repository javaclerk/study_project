#include <iostream>

using namespace std;

#ifndef Led_h
#define Led_h

class Led
{
  public:
    Led(int led);
    void blink();
  private:
    int _led;
};

#endif