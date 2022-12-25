
#ifndef INDEXOUTOFBOUNDS_HPP
#define INDEXOUTOFBOUNDS_HPP
#include "Exception.hpp"

class IndexOutOfBounds : public Exception {
public:

    IndexOutOfBounds(const std::string &msg) : Exception(msg) {
    }
};


#endif 

