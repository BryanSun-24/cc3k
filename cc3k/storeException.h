#ifndef STOREEXCEPTION_H
#define STOREEXCEPTION_H

#include "Exception.h"
#include <string>

class StoreException :public Exception{
    public:
    std::string message() override {
        return "unable to buy from Merchant!";
    }
};


#endif
