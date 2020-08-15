#ifndef ATTACKEXCEPTION_H
#define ATTACKEXCEPTION_H

#include "exception.h"
#include <string>

class AttackException:public Exception{
    public:
    std::string message() override {
        return "that's not an Enemy!";
    }
};


#endif

