#include<iostream>
#include<fstream>
#include<string>

#include"includes/led.h"

using namespace std;

int led_on(){
    std::ofstream out("/sys/class/gpio/gpio487/value");
    std::ofstream out("/sys/class/gpio/gpio488/value");
    std::ofstream out("/sys/class/gpio/gpio489/value");
    std::ofstream out("/sys/class/gpio/gpio490/value");
    std::ofstream out("/sys/class/gpio/gpio491/value");
    
    std::string s;
    if (out.is_open()) {
        out << "1";
    }

    return 0;
}

int led_off(){
    std::ofstream out("/sys/class/gpio/gpio487/value");
    std::ofstream out("/sys/class/gpio/gpio488/value");
    std::ofstream out("/sys/class/gpio/gpio489/value");
    std::ofstream out("/sys/class/gpio/gpio490/value");
    std::ofstream out("/sys/class/gpio/gpio491/value");
    
    std::string s;
    if (out.is_open()) {
        out << "0";
    }

    return 0;
}