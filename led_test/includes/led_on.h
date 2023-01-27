#include <cstdlib>
#include <iostream>

#ifndef LEDON_H
#define LEDON_H

using namespace std;

class Led_On{

    public:
        std::cout << echo 0 > /sys/class/gpio/gpio487/value << endl;
};

#endif