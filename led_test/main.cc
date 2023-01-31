#include<iostream>
#include<fstream>
#include<string>

#include "leds/led.h"

using namespace std;

int main(){

    fiveg_led fiveg_led;
    gnss_led gnss_led;
    pwr_led pwr_led;
    v2x_led v2x_led;
    wave_led wave_led;

    int num,g_num;

    std::cout << "LED control Program" << endl;
    std::cout << "--------------------" << endl;
    std::cout << "Please Choose control pannel" << endl;
    std::cout << "--------------------" << endl;
    std::cout << "1.Power_LED 2.5G_LED 3.C-V2X_LED 4.WAVE_LED 5.GNSS_LED" "6.EXIT"<< endl;
    std::cin >> num;
    

    if(num == 1){
        std::cout << "Power_LED" << endl;
        std::cout << "Light Status (0 or 1)" << endl;
        cin >> g_num;
        if(g_num == 1){
            pwr_led.On();
        }
        else{
            pwr_led.Off();
        }
    }
    else if(num == 2){
        std::cout << "5G_LED" << endl;
        std::cout << "Light Status (0 or 1)" << endl;
        cin >> g_num;
        if(g_num == 1){
            fiveg_led.On();
        }
        else{
            fiveg_led.Off();
        }
    }
    else if(num == 3){
        std::cout << "C-V2X_LED" << endl;
        std::cout << "Light Status (0 or 1)" << endl;
        cin >> g_num;
        if(g_num == 1){
            v2x_led.On();
        }
        else{
            v2x_led.Off();
        }
    }
    else if(num == 4){
        std::cout << "WAVE_LED" << endl;
        std::cout << "Light Status (0 or 1)" << endl;
        cin >> g_num;
        if(g_num == 1){
            wave_led.On();
        }
        else{
            wave_led.Off();
        }
    }
    else if(num == 5){
        std::cout << "GNSS_LED" << endl;
        std::cout << "Light Status (0 or 1)" << endl;
        cin >> g_num;
        if(g_num == 1){
            gnss_led.On();
        }
        else{
            gnss_led.Off();
        }
    }
    else{
        std::cout << "Invalid Command !!!" << endl;
    }
    return 0;
}
