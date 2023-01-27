#include<iostream>
#include<fstream>
#include<string>

#ifndef 5G_LED_H
#define 5G_LED_H

using namespace std;

class fiveg_led{
    int pat;
    public:
        int led();
}

/*int fiveg_main(){
    string out_line;
    ofstream out("/sys/class/gpio/gpio490/value");
    for(int i=0;i<=1;i++){
        cin>>out_line;
        out<<out_line<<endl;
    }
out.close();

return 0;
}
*/
#endif