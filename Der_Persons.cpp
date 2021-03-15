#include "Der_Persons.h"// (без изменения)
#include"Der_Pers.h"



void Persons::Swap(int i, int j) // Переставить элементы i и j массива G
{
    Pers tmp = G[i];
    G[i] = G[j];
    G[j] = tmp;
}
//Реализация метода сортировки, Compare  критерий– указатель на функцию сравнения сведений о 2х людях
void Persons::SortPersons(bool (*Compare)(const Pers&, const Pers&))     // метод пузырька
{
    for (int i = G.size() - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (!Compare(G[j], G[j + 1])) // Если не тот порядок,
                Swap(j, j + 1);
}    // переставить элементы
// Реализация функций-друзей класса Persons
ostream& operator<<(ostream& os, const Persons& group) // Вывод списка группы
{
    for (int i = 0; i < group.G.size(); i++) // Вывод данных
        os << group.G[i]; // о каждом человеке
    return os;
}
istream& operator>>(istream& is, Persons& group) // Чтение данных о группе из файла
{
    Pers tmp; // Сведения о человеке
    while (!is.eof()) {
        is >> tmp; // Чтение сведений о человеке
        if (is.eof()) // Если достигнут конец файла,
            break; // выход из цикла
        group.Add(tmp);
    } // Добавление сведений в группу
    return is;
}
