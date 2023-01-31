#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class wave_led{
public:
int num;
string s;

void On();
void Off();
};

void wave_led::On(){
    std::ofstream out("/sys/class/gpio/gpio488/value", std::ios::ate);
    if (out.is_open()){
        out << "1";
    }
} 


void wave_led::Off(){
    std::ofstream out("/sys/class/gpio/gpio488/value", std::ios::ate);
    if (out.is_open()){
        out << "0";
    }
}

