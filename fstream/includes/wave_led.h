#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int wave_led(){
    std::ifstream in("/sys/class/gpio/gpio488/value");
    std::string s;

    if (in.is_open()) {
        in >> s;
        std::cout << " 점등 여부 (1 or 0) :: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다! " << std::endl;
    }
    return 0;
}
