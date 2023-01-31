#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class gnss_led{
public:
int num;
string s;

void On();
void Off();
};

void gnss_led::On(){
    std::ofstream out("/sys/class/gpio/gpio487/value", std::ios::ate);
    if (out.is_open()){
        out << "1";
    }
}


void gnss_led::Off(){
    std::ofstream out("/sys/class/gpio/gpio487/value", std::ios::ate);
    if (out.is_open()){
        out << "0";
    }
}
