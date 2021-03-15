#ifndef ClassDateH
#define ClassDateH
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Date { // Класс для работы с датами
	int d, m, y; // День, месяц, год
public:
	Date(int  dd = 0, int  mm = 0, int  yy = 0);   // Конструктор
	Date(const Date& D) // Конструктор копирования
	{
		d = D.d; m = D.m; y = D.y;
	}
	Date& operator=(const Date& D);// Оператор присваивания
	bool operator<=(const Date& D) const // Сравнение двух дат
	// Слово const в заголовке  означает, что она не изменяет объект класса для которого вызывается
	{
		return (y < D.y) || (y == D.y && m < D.m) || (y == D.y && m == D.m && d <= D.d);
	}
	friend ostream& operator<<(ostream& os, const Date& dt)// Вывод даты
	{
		return os << setw(2) << setfill('0') << dt.d << '.' << setw(2) << setfill('0') << dt.m << '.' << dt.y << endl;
	}
	friend istream& operator>>(istream& is, Date& dt)// Ввод даты
	{
		return is >> dt.d >> dt.m >> dt.y;
	}
};

#endif

