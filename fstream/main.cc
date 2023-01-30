#include<iostream>
#include<fstream>
#include<string>

#include "includes/led.h"

using namespace std;

int main(){
    std::cout << "LED 제어 프로그램" << endl;
    std::cout << "--------------------" << endl;

    std::ifstream in("/sys/class/gpio/gpio490/value");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        return 0;
    }
   
        std::string s;
    while (in) {
        in.getline(buf, 100, '.');
        std::cout << buf << std::endl;
    }

    return 0;
}