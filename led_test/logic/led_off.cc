#include <filesystem>
#include <fstream>
#include <iostream>

#include "led_off.h"

using namespace std;

int main(){
    std::filesystem::path p("/sys/class/gpio/gpio498/value");

    std::cout << "Does" << p << " exist?[" << std::boolalpha
                << std::filesystem::exists(p) << "]" << std::endl;
    std::cout << "Is" << p << " file?" << std::filesystem::is_regular_file(p)
                << "[" << std::endl;
    std::cout << "Is" << p << " directory? [" << std::filesystem::is_directory(p)
                << "]" std::endl;
}