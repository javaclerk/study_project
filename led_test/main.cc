#include<iostream>
#include<fstream>
#include<string>

#include "includes/led.h"

using namespace std;

int main(){
    int num;

    std::cout << "LED control Program" << endl;
    std::cout << "--------------------" << endl;
    std::cout << "Please Choose control pannel" << endl;
    std::cin >> num;

    std::string s;

    if(num == 1){
        std::ofstream out("/sys/class/gpio/gpio487/value", std::ios::ate);
        if (out.is_open()){
            out << "1";
        }
    return 0;
    }

    else if(num == 0){
    std::ofstream out("/sys/class/gpio/gpio487/value", std::ios::ate);
        if(out.is_open()){
            out << "0";
        }
    return 0;
    }   
}




