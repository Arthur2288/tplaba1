#include "member.h" 
#include "human.h" 
#include <string>
using namespace std;
Member::Member(std::string fio, std::string mother, std::string father, std::string suprug, int kol_det, std::string* chield, date dr, date ds, int age)
{
    setlocale(LC_ALL, "Russian");
    this->fio = fio;
    std::cout << fio;
    this->mother = mother;     
    this->father = father;     
    this->suprug = suprug;   
    this->child = new string[kol_det];
    for (int i = 0; i < kol_det; i++)
    {
        this->child[i] = chield[i];
    }
    this->koldet = kol_det;
    this->dr = dr;
    this->ds = ds;
    this->age = age;
    

    std::cout << "Member default constructor called\n";
}

Member::Member(std::string parameters)
{
    this->fio = parameters.substr(0, parameters.find('!')); 
    parameters.erase(0, parameters.find('!') + 1); 
    this->mother = parameters.substr(0, parameters.find('!'));
    parameters.erase(0, parameters.find('!') + 1);     
    this->father = parameters.substr(0, parameters.find('!'));
    parameters.erase(0, parameters.find('!') + 1);     
    this->suprug = (parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1); 
    this->koldet = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);
    child = new string[koldet];
    for (int i = 0; i < koldet; i++)
    {
        this->child[i] = parameters.substr(0, parameters.find('!'));
        parameters.erase(0, parameters.find('!') + 1);
    }
    this->dr.day = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);
    this->dr.mounth = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);
    this->dr.year = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);

    this->ds.day = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);
    this->ds.mounth = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);
    this->ds.year = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);

    this->age = stoi(parameters.substr(0, parameters.find('!')));
    parameters.erase(0, parameters.find('!') + 1);

    std::cout << "Member load-from-file constructor called\n";
}

Member::~Member()
{
    std::cout << "Member default destructor called\n";
}

void Member::print() 
{
    setlocale(LC_ALL, "Russian");
    //std::cout << getParam() << "\n";
    std::cout << "фио: " << fio << "\n";
    std::cout << "фио мамы: " << mother << "\n";
    std::cout << "фио папы: " << father << "\n";
    std::cout << "фио супруга: " << suprug << "\n";
    std::cout << "дети:" << "\n";
    for (int i = 0; i < koldet; i++)
    {
        std::cout << child[i] << "\n";
    }
    std::cout << "дата рождения: " << dr.day << "." << dr.mounth << "." << dr.year << "\n";
    if (ds.year > 0)
    {
        std::cout << "дата смерти: " << ds.day << "." << ds.mounth << "." << ds.year << "\n";
    }
    std::cout << "возраст: " << age << "\n";
}

std::string Member::getParam() {
    std::string parameters;
    parameters = "";
    parameters += fio;
    parameters += "!";
    parameters += mother;
    parameters += "!";
    parameters += father;
    parameters += "!";
    parameters += suprug;
    parameters += "!";
    parameters += to_string(koldet);
    parameters += "!";
    for (int i = 0; i < koldet; i++)
    {
        parameters += child[i];
        parameters += "!";

    }
    parameters += to_string(dr.day);
    parameters += "!";
    parameters += to_string(dr.mounth);
    parameters += "!";
    parameters += to_string(dr.year);
    parameters += "!";
    parameters += to_string(ds.day);
    parameters += "!";
    parameters += to_string(ds.mounth);
    parameters += "!";
    parameters += to_string(ds.year);
    parameters += "!";
    parameters += to_string(age);
    parameters += "!";
    

    return parameters;

}
std::string Member::getName()
{
    return fio;
}
std::string Member::getMother()
{
    return mother;
}
std::string Member::getFather()
{
    return father;
}