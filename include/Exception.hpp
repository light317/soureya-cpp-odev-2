
/* 
 * File:   Exception.hpp
 * Author: HAKAN
 *
 * Created on November 1, 2022, 7:12 AM
 */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
// using namespace std;

class Exception {
private:
    std::string message;
public:

    Exception(const std::string &msg) : message(msg) {
    }
    std::string Message()const;
};


#endif /* EXCEPTION_HPP */

