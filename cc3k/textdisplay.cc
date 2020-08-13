#include "textdisplay.h"
#include <fstream>
#include <sstream>
#include <iostream>

Textdisplay::Textdisplay(int row, int col) {
    for(int i = 0; i < row; ++i){
        std::vector<char> v;
        this->theDisplay.emplace_back(v);
    }

    std::ifstream in{"defaultMap.txt"};
    std::string line;
    char c;
    
    for(int i = 0; i < row; ++i){
        getline(in, line);
        int len = line.length();
        for(int j = 0; j < col; ++j){
            this->theDisplay[i].emplace_back(line[j]);
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Textdisplay &td){
    for(size_t i = 0; i < td.theDisplay.size(); ++i){
        for(size_t j = 0; j < td.theDisplay.at(i).size(); ++j){
            out << td.theDisplay.at(i).at(j);
        }
        out << std::endl;
    }
    return out;
}

void Textdisplay::print(){
    std::cout << (*this); 
}

