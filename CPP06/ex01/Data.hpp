#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
public:
    int id;
    std::string name;

    // Default constructor
    Data();
    // Copy constructor
    Data(const Data &other);
    // Assignment operator
    Data &operator=(const Data &other);
    // Destructor
    ~Data();
};

#endif

