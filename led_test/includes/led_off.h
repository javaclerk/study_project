#include <iostream>
#include <fstream>

#ifndef LEDOFF_H
#define LEDOFF_H

using namespace std;

class Led_Off{

    public:
        echo 0 > /sys/class/gpio/gpio487/value

};

#endif