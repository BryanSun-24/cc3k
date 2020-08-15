#ifndef MOVEEXCEPTION_H
#define MOVEEXCEPTION_H

#include "exception.h"
#include <string>

class MoveException:public Exception{
    public:
    std::string message() override {
        return "please provide a valid direction";
    }
};


#endif

