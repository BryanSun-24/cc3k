#ifndef PICKEXCEPTION_H
#define PICKEXCEPTION_H

#include "exception.h"
#include <string>

class PickException:public Exception{
    public:
    std::string message() override {
        return "unable to pick this gold!";
    }
};


#endif

