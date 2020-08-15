#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception{
    public:
    virtual std::string message() = 0;
};


#endif

