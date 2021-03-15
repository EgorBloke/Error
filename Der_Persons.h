#ifndef Der_PersonsH
#define Der_PersonsH
#include "Der_Pers.h" // Подключение класса Pers
class Persons // Класс для работы с группой лиц
{
    vector<Pers> G; // Вектор сведений о людях
public:
    void Add(const Pers& pd) // Добавление человека в группу нового человека
    {
        G.push_back(pd);
    }
    // Сортировка по критерию, задаваемому функцией сравнения Compare()
    //Аргументом функции сортировки  является указатель Compare на функцию, 
    //которая сравнивает личные сведения двух людей (по имени или дате)
    void SortPersons(bool (*Compare)(const Pers&, const Pers&));
    // Вывод сведений о группе лиц
    friend ostream& operator<<(ostream&, const Persons&);
    // Ввод сведений о группе лиц
    friend istream& operator>>(istream&, Persons&);
private:
    void Swap(int i, int j); // Поменять местами элементы i и j массива G
};
#endif
