#include "Led.h"

Led::Led(int led)
{
  _led = led;
}

void Led::blink()
{
  cout << "blink" << " " << _led << endl;
}