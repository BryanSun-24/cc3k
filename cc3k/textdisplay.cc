#include "textdisplay.h"
#include <fstream>
#include <sstream>
#include <iostream>

Textdisplay::Textdisplay(int row, int col) {
    prevSymbol = '.';
    for(int i = 0; i < row; ++i){
        std::vector<char> v;
        this->theDisplay.emplace_back(v);
    }

    std::ifstream in{"defaultMap.txt"};
    std::string line;
    
    for(int i = 0; i < row; ++i){
        getline(in, line);
        int len = line.length();
        for(int j = 0; j < col; ++j){
            this->theDisplay[i].emplace_back(line[j]);
        }
    }
}

void Textdisplay::print(){
    std::cout << (*this); 
}

void Textdisplay::setPlayer(int row, int col){
    this->theDisplay[row][col] = '@';
}

void Textdisplay::setSymbol(int row, int col){
    this->theDisplay[row][col] = this->prevSymbol;
}

bool Textdisplay::validMove(int row, int col){
    if(this->theDisplay[row][col] == '.' || this->theDisplay[row][col] == '+' || this->theDisplay[row][col] == '#' || this->theDisplay[row][col] == '\\' || this->theDisplay[row][col] == 'G'){
        return true;
    } else {
        return false;
    }
}

bool Textdisplay::validMovePotion(int row, int col){
    if(this->theDisplay[row][col] == 'P'){
        return true;
    } else {
        return false;
    }
}

void Textdisplay::updateSymbol(int row, int col){
    if(this->theDisplay[row][col] != '+' && this->theDisplay[row][col] != '.' &&this->theDisplay[row][col] != '#'){
        this->prevSymbol = '.';
    }else{
        this->prevSymbol = this->theDisplay[row][col];
    }
}

bool Textdisplay::checkStair(int nextRow,int nextCol){
    if(this->theDisplay[nextRow][nextCol] == '\\'){
        return true;
    } else {
        return false;
    }
}

bool Textdisplay::checkEmpty(int row, int col){
    if(this->theDisplay[row][col] == '.'){
        return true;
    } else {
        return false;
    }
}

char Textdisplay::getSymbol(int row, int col){
    return this->theDisplay[row][col];
}

void Textdisplay::setStairs(int row, int col){
    this->theDisplay[row][col] = '\\';
}

void Textdisplay::setPotion(int row,int col){
    this->theDisplay[row][col] = 'P';
}

void Textdisplay::setGold(int row, int col){
    this->theDisplay[row][col] = 'G';
}

void Textdisplay::setHuman(int row, int col){
    this->theDisplay[row][col] = 'H';
}

void Textdisplay::setDwarf(int row, int col){
    this->theDisplay[row][col] = 'W';
}

void Textdisplay::setElf(int row, int col){
    this->theDisplay[row][col] = 'E';
}

void Textdisplay::setOrcs(int row, int col){
    this->theDisplay[row][col] = 'O';
}

void Textdisplay::setMerchant(int row, int col){
    this->theDisplay[row][col] = 'M';
}

void Textdisplay::setHalfling(int row, int col){
    this->theDisplay[row][col] = 'L';
}

std::ostream &operator<<(std::ostream &out, const Textdisplay &td){
    for(size_t i = 0; i < td.theDisplay.size(); ++i){
        for(size_t j = 0; j < td.theDisplay.at(i).size(); ++j){
            if(td.theDisplay.at(i).at(j) == '-' || td.theDisplay.at(i).at(j) == '|'){
                out << BOLDBLACK << td.theDisplay.at(i).at(j);
            } 
            else if(td.theDisplay.at(i).at(j) == 'G' ){
                out << BOLDYELLOW << td.theDisplay.at(i).at(j);
            } 
            else if(td.theDisplay.at(i).at(j) == 'P' ){
                out << BOLDGREEN << td.theDisplay.at(i).at(j);
            }
            else if(td.theDisplay.at(i).at(j) == '\\' || td.theDisplay.at(i).at(j) == '@' ){
                out << BOLDRED << td.theDisplay.at(i).at(j);
            }
             else if(td.theDisplay.at(i).at(j) == '#' ){
                out << BOLDBLUE << td.theDisplay.at(i).at(j);
            }
            else {
                 out << REST << td.theDisplay.at(i).at(j);
            }
        }
        out << std::endl;
    }
    return out;
}
