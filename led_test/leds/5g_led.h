#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class fiveg_led{
public:
int num;
string s;

void On();
void Off();
};

void fiveg_led::On(){
    std::ofstream out("/sys/class/gpio/gpio490/value", std::ios::ate);
    if (out.is_open()){
        out << "1";
    }
}


void fiveg_led::Off(){
    std::ofstream out("/sys/class/gpio/gpio490/value", std::ios::ate);
    if (out.is_open()){
        out << "0";
    }
}

