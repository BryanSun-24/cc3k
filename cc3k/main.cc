#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream in{"defaultMap.txt"};
    std::string map;
    while(getline(in, map)){
        std::cout << map << std::endl;
    }

    return 0;
}

