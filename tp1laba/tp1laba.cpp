#include <iostream> 
#include <string> 
#include "keeper.h" 
#include "member.h" 
#include <locale>
 

using namespace std;

void showMenu()
{
    std::cout << "\nMenu:\n"
        "1. Добавьте члена семьи\n"
        "2. Удалите члена семьи\n"
        "3. Вывести фамильное дерево\n"
        "4. Сохранить файл\n"
        "5. Прочитать файл\n"
        "6. Выход\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Keeper keeper;     
    while (true)
    {
        showMenu();         
        int choice;         
        cout << "\nВыберите действие:\n";         
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try 
        {
            switch (choice) 
            {
                case 1: 
                {                    

                    string fio;                             
                    string mother;                             
                    string father;  
                    string suprug;
                    int kol_det;
                    int age;                                                          
                    Member* mem;
                    string* child = NULL;
                    cout << "Введите фио члена семьи: ";
                    getline(cin,fio); 
                    cout << "Введите фио мамы: ";
                    getline(cin,mother);
                    cout << "Введите фио папы: ";
                    getline(cin,father);
                    cout << "Введите фио супруга: ";                             
                    getline(cin ,suprug);
                    cout << "Введите кол-во детей: ";
                    cin >> kol_det;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    child = new string[kol_det];
                    for (int i = 0; i < kol_det; i++)
                    {
                        string name;

                        cout << "Введите фио " << i+1 << " ребенка: ";
                        getline(cin,name);
                        child[i] = name;
                    }
                    
                    date dr, ds;
                    cout << "Введите дату рождения:\n";
                    cout << "День: ";
                    cin >> dr.day;
                    cout << "Месяц: ";
                    cin >> dr.mounth;
                    cout << "Год: ";
                    cin >> dr.year;
                    cout << "Этот человек жив?(yes/no):";
                    string life;
                    cin >> life;
                    if (life == "no")
                    {
                        cout << "Введите дату смерти:\n";
                        cout << "День: ";
                        cin >> ds.day;
                        cout << "Месяц: ";
                        cin >> ds.mounth;
                        cout << "Год: ";
                        cin >> ds.year;
                    }
                    else 
                    {
                        ds.day = 0;
                        ds.mounth = 0;
                        ds.year = 0;
                    }
                    

                    cout << "Введите возраст члена семьи: ";
                    cin >> age;
                    
                    
                    mem = new Member(fio, mother, father, suprug, kol_det, child, dr, ds, age);
                    keeper.add(mem);                             
                    break;
                }                         
            
                case 2: 
                { 
                    int index; 
                    keeper.print();
                    cout << "Enter  index:\n";                     
                    cin >> index;                     
                    keeper.remove(index);                     
                    break; 
                }                 
                case 3: 
                { 
                    keeper.printTree(0,0);                   
                    break; 
                }                
                case 4: 
                {
                    keeper.save("output.txt");
                    break;
                }                 
                case 5: 
                { 
                    keeper.load("output.txt");       
                    break; 
                }                 
                case 6: 
                { 
                    cout << "Goodbye!\n";       
                    return 0; 
                }               
                default: 
                {
                    cout << "Invalid choice\n";              
                    break;
                }
            }
        }
        catch (Exception error)
        {
            cout << error;
        }
    }
}
