#include<iostream>
#include<fstream>
#include<string>

#include "includes/led.h"

using namespace std;


/*led를 모두 켜는 동작*/
int led_all_on(){
    std::ofstream out("/sys/class/gpio/gpio487/value", std::ios::ate);
    
    std::string s;
        if(out.is_open())
    {
        out << "1";
    }

    return 0;
}


/*led를 모두 끄는 동작*/
int led_all_off()
{
    std::ofstream out("/sys/class/gpio/gpio487/value", std::ios::ate);
         std::string s;
    if (out.is_open()) {
        out << "0";
    }

    return 0;
}

int main(){
    int num;

    std::cout << "LED control Program" << endl;
    std::cout << "--------------------" << endl;
    std::cout << "Please Choose control pannel" << endl;
    std::cin >> num;

    if(num == 1){
        led_all_on;
    }
    else if(num == 0){
        led_all_off;
    }

    return 0;
}



