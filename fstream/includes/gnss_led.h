#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int gnss_main(){
    string out_line;
    ofstream out("/sys/class/gpio/gpio487/value");
    for(int i=0;i<=1;i++){
        cin>>out_line;
        out<<out_line<<endl;
    }

out.close();

return 0;
}