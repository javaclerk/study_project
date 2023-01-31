#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class fiveg_pattern{
public:
int num;
string s;
void 1();
void 2();
};

void fiveg_pattern::1(){

    while(break;);

    std::ofstream out("/sys/class/gpio/gpio490/value", std::ios::ate);
    if (out.is_open()){
        out << "1";
    }
}


void fiveg_pattern::2(){
    std::ofstream out("/sys/class/gpio/gpio490/value", std::ios::ate);
    if (out.is_open()){
        out << "0";
    }
}

