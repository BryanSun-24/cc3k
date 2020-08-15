#ifndef RESTARTEXCEPTION_H
#define RESTARTEXCEPTION_H

#include "Exception.h"
#include <string>

class RestartException :public Exception{
    public:
    std::string message() override {
        return "";
    }
};


#endif

