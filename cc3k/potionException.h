#ifndef POTIONEXCEPTION_H
#define POTIONEXCEPTION_H

#include "exception.h"
#include <string>

class PotionException:public Exception{
    public:
    std::string message() override {
        return "that's not a Potion!";
    }
};


#endif

