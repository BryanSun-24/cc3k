#ifndef DIEEXCEPTION_H
#define DIEEXCEPTION_H

#include "Exception.h"
#include <string>

class DieException :public Exception{
    public:
    std::string message() override {
        return "Sorry, you Lost!";
    }
};


#endif

