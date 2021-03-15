#ifndef Der_PersH
#define Der_PersH
#include "ClassDate.h"
class Pers;

bool CmpDate(const Pers& ps1, const Pers& ps2);

bool CmpName(const Pers& ps1, const Pers& ps2);

class Pers : public Date 
{
	string name; 
	Pers(const string& nm, const Date& D) : Date(D), name(nm) // Конструктор с параметрами
	{ }
	Pers() : Date(), name() 
	{ } // Пустая строка как имя
	Pers(const Pers& ps) : Date(ps), name(ps.name) // Конструктор копирования
	{ }
	Pers& operator = (const Pers&); // Оператор присваивания
	friend ostream& operator<<(ostream& os, const Pers& ps) // Вывод сведений о человеке
	{
		return os << ps.name << "     \t" << Date(ps);
	}
	friend istream& operator>>(istream& is, Pers& ps); // Оператор ввода сведений о человеке
	// CmpDate: возвращает true, если дата объекта ps1  более ранняя или та же, что и у объекта ps2
	friend bool CmpDate(const Pers& ps1, const Pers& ps2);
// CmpName: сравнение фамилий
	friend bool CmpName(const Pers& ps1, const Pers& ps2); // CmpName: сравнение фамилий
};

#endif
