#include <iostream>

#ifndef LEDOFF_H
#define LEDOFF_H

using namespace std;

class Led_Off{

    public:
        std::cout << echo 0 > /sys/class/gpio/gpio487/value << endl;

};

#endif