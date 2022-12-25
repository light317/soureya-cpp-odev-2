
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>

class Exception {
private:
    std::string message;
public:

    Exception(const std::string &msg) : message(msg) {
    }
    std::string Message()const;
};


#endif 

