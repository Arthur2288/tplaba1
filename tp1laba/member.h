#ifndef TP_1LABA_PERCUSSION_H 
#define TP_1LABA_PERCUSSION_H 
#include <locale>
#include "Human.h"

struct date
{
    int day;
    int mounth;
    int year;
};
class Member : public Human
{
private:
    std::string fio;
    std::string mother;
    std::string father;
    std::string suprug;
    std::string* child;
    int koldet;
    date dr;
    date ds;
    int age;
public:
    Member(std::string fio, std::string mother, std::string father, std::string suprug, int kol_det, std::string* child, date dr, date ds, int age);
    explicit Member(std::string parameters);
    ~Member();
    void print();
    std::string getParam();
    std::string getMother();
    std::string getFather();
    std::string getName();
};

#endif 