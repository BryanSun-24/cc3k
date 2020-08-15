#ifndef POTIONEXCEPTION_H
#define POTIONEXCEPTION_H

#include "Exception.h"
#include <string>

class PotionException :public Exception{
    public:
    std::string message() override {
        return "that's not a Potion!";
    }
};


#endif

