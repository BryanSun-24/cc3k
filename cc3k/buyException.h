#ifndef BUYEXCEPTION_H
#define BUYEXCEPTION_H

#include "Exception.h"
#include <string>

class BuyException :public Exception{
    public:
    std::string message() override {
        return "that's not a Merchant!";
    }
};


#endif

