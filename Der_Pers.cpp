#include "Der_Pers.h"
// Реализация функции-члена класса Pers

Pers& Pers::operator=(const Pers& ps) // Оператор присваивания
{
	if (this != &ps) { // Если присваивание не самому себе,
		name = ps.name; // копирование имени,
		Date::operator=(ps); //копирование даты (Прямое присваивание вида: d = ps.d;m = ps.m;y = ps.y;недопустимо)
	}     // возможна конструкция вида this->Date::operator=(ps);
	return *this; // Возвращение ссылки на объект
}
// Ввод данных об одном человеке
istream& operator>>(istream& is, Pers& ps)
{
	is >> (Date&)ps; // Ввод даты рождения
 // ссылка на объект ps типа Pers приводится к типу ссылки на Date
	getline(is, ps.name); // Ввод фамилии и имени (инициалов)
	// Поиск позиции первого непробельного символа в строке с фамилией
	int indexNotSpaceTab = ps.name.find_first_not_of(" \t");
	// Удаление начальных пробелов
	ps.name = ps.name.substr(indexNotSpaceTab, ps.name.length());
	return is;
}
bool CmpDate(const Pers& ps1, const Pers& ps2)
{
	return ps1 <= ps2;
}        // Используется функция-оператор сравнения дат
// CmpName: сравнение фамилий
bool CmpName(const Pers& ps1, const Pers& ps2) // CmpName: сравнение фамилий
{
	return ps1.name <= ps2.name;
}