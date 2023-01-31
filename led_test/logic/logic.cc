#include<iostream>
#include<fstream>
#include<string>

#include"leds/led.h"

using namespace std;


//패턴 선언부
class pattern{
public:
static int led_num;

void pattern1();
void pattern2();
void pattern3();
};

void pattern1(){
    if(pattern::led_num == 1)
    {   
        
    }
}