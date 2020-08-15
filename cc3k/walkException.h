#ifndef WALKEXCEPTION_H
#define WALKEXCEPTION_H

#include "exception.h"
#include <string>

class WalkException :public Exception{
    public:
    std::string message() override {
        return "you can't walk over it";
    }
};


#endif

