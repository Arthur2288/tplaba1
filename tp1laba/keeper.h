#ifndef TP_1LABA_KEEPER_H 
#define TP_1LABA_KEEPER_H 

#include "human.h" 
#include "Exception.h" 

class Keeper {
private:     
Human** members; 
int numMembers;

public:
    Keeper();
    ~Keeper();     
    void add(Human* member);     
    void print();     
    void remove(int index);     
    void save(std::string fileName);     
    void load(std::string fileName);
    void printTree(int n, int l);
};

#endif 

