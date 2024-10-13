#ifndef TP_1LABA_ORCHESTRA_H 
#define TP_1LABA_ORCHESTRA_H 

#include <iostream> 

class Human
{
public:
    Human()
    {
        std::cout << "Human default constructor called" << std::endl;
    }
    virtual ~Human()
    {
        std::cout << "Human destructor called" << std::endl;
    }
    virtual void print() = 0;
    virtual std::string getParam() = 0;
    virtual std::string getName() = 0;
    virtual std::string getMother() = 0;
    virtual std::string getFather() = 0;
};

#endif
