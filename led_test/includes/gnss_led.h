#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int gnss_led(){
    std::ifstream in("/sys/class/gpio/gpio487/value");
    std::string s;
    char buf[100];

    if (in.is_open()) {
        in >> s;
        std::cout << " Lighting Status (1 or 0) :: " << s << std::endl;
    }
     
    else {
        std::cout << " File Has not Founded! " << std::endl;
    }

    if (!in.is_open()) {
        std::cout << " File Has not Founded! " << std::endl;
        return 0;
    }
    
    while (in) {
        in.getline(buf, 100, '.');
        std::cout << buf << std::endl;
    }

    return 0;
}

