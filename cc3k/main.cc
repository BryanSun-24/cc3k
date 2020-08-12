#include <iostream>
#include <fstream>
#include <string>

int main(){
    // 5个floor， 每一个floor都有一个textdisplay

    std::ifstream in{"defaultMap.txt"};
    std::string map;
    while(getline(in, map)){
        std::cout << map << std::endl;
    }

    return 0;
}

