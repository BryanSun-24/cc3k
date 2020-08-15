#ifndef QUITEXCEPTION_H
#define QUITEXCEPTION_H

#include "Exception.h"
#include <string>

class QuitException :public Exception{
    public:
    std::string message() override {
        return "";
    }
};


#endif

