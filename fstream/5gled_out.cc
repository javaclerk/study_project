#include<iostream>
#include<fstream>
#include<string>

#include "includes/5g_led.h"

using namespace std;

int fiveg_led :: led(){
string out_line;
    ofstream out("/sys/class/gpio/gpio489/value");
    for(int i=0;i<=1;i++){
        cin>>out_line;
        out<<out_line<<endl;
    }
    out.close();
};

int fiveg_led::led(){
    
}