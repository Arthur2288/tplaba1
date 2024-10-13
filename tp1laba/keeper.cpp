#include "keeper.h" 
#include "string.h" 
#include "member.h"  
#include <fstream> 
#include <string>

Keeper::Keeper()
{
    members = nullptr;     
    numMembers = 0;     
    std::cout << "Keeper default constructor called\n";
}

Keeper::~Keeper()
{
    for (int i = 0; i < numMembers; i++)
    {
        delete members[i];
    }
    delete[] members;

    std::cout << "Keeper default destructor called\n";
}

void Keeper::add(Human* instrument)
{
    Human** newmembers = new Human * [numMembers + 1];     
    for (int i = 0; i < numMembers; i++)
    {
        newmembers[i] = members[i];
    }
    newmembers[numMembers] = instrument;     
    numMembers++;
    delete[] members;     
    members = newmembers;
}

void Keeper::printTree(int n,int l)
{
    if (numMembers == 0)
        throw Exception("There are no objects!\n");
    std::cout << "=== Уровень " << l <<"\n";
    members[n]->print();
    std::string MotherName = members[n]->getMother();
    for (int j = 0; j < numMembers; j++)
    {
        if (members[j]->getName() == MotherName)
        {
            std::cout << "***Мать: \n";
            printTree(j,l+1);
        }
    }
    std::string FatherName = members[n]->getFather();
    for (int j = 0; j < numMembers; j++)
    {
        if (members[j]->getName() == FatherName)
        {
            std::cout << "***Отец: \n";
            printTree(j,l+1);
        }
    }
}
void Keeper::print()
{
    if (numMembers == 0)         
        throw Exception("There are no objects!\n");     
    for (int i = 0; i < numMembers; i++)
    {
        std::cout << i << ". ";
        members[i]->print();
        /*std::string MotherName = members[i]->getMother();
        for (int j = 0; j < numMembers; j++)
        {
            if (members[j]->getName()==MotherName)
            {
                std::cout << "Мать: ";
                members[j]->print();
            }
        }
        std::string FatherName = members[i]->getFather();
        for (int j = 0; j < numMembers; j++)
        {
            if (members[j]->getName() == FatherName)
            {
                std::cout << "Отец: ";
                members[j]->print();
            }
        }
        */
    }
}


void Keeper::remove(int index)
{
    if (index >= numMembers || index < 0)         
        throw Exception("There is no such object!\n");
    Human** newmembers = new Human * [numMembers - 1];
    int j = 0;     
    for (int i = 0; i < numMembers; i++)
    {
        if (i != index)
        {
            newmembers[j++] = members[i];
        }
    }
    delete[] members;     
    members = newmembers;     
    numMembers--;
}

void Keeper::save(std::string filename)
{
    std::ofstream file(filename);     
         
    for (int i = 0; i < numMembers; i++) {
        file << members[i]->getParam() << "\n";
    }     
    file.close();
}

void Keeper::load(std::string filename)
{
    std::ifstream file(filename);     
    std::string s;     
    while (getline(file, s))
    {
        std::string parameters;         
        
        //s.erase(0, s.find(' ') + 1);         
        parameters = s;         
        std::cout << parameters << std::endl;         
        
        Member* mem;             
        mem = new Member(parameters);             
        this->add(mem);
        
    }     
    file.close();
}
