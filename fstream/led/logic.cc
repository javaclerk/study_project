#include<iostream>
#include<fstream>
#include<string>

#include "includes/wave_led.h"
#include "includes/5g_led.h"
#include "includes/gnss_led.h"
#include "includes/rwr_led.h"
#include "includes/v2x_led.h"

using namespace std;

class led_on{
    public:
    int out_line;
        ofstream out("/sys/class/gpio/gpio488/value");
        for(int i=0;i<=1;i++){
            cin>>out_line;
            out<<out_line<<endl;
        }
    out.close();
};

int main(){
   
}