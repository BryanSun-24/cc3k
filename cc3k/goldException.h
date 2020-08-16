#ifndef GOLDEXCEPTION_H
#define GOLDEXCEPTION_H

#include "Exception.h"
#include <string>

class GoldException :public Exception{
    public:
    std::string message() override {
        return "You dont have enough Gold to trade";
    }
};


#endif

