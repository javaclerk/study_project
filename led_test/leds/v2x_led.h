#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class v2x_led{
public:
int num;
string s;

void On();
void Off();
};

void v2x_led::On(){
    std::ofstream out("/sys/class/gpio/gpio489/value", std::ios::ate);
    if (out.is_open()){
        out << "1";
    }
}


void v2x_led::Off(){
    std::ofstream out("/sys/class/gpio/gpio489/value", std::ios::ate);
    if (out.is_open()){
        out << "0";
    }
}
