#include "ClassDate.h"
#pragma warning(disable : 4996)
Date& Date:: operator=(const Date& D) // Оператор присваивания
{
	if (this != &D)
	{
		d = D.d; m = D.m; y = D.y;
	}
	return *this;
}
// Конструктор класса Date
Date::Date(int dd, int mm, int yy) // Значения аргументов по умолчанию второй раз не указываются
{
	time_t seconds; // Переменная для секунд
	time(&seconds); // Число секунд от 01.01.1970
	struct tm* ptm_time; // Указатель на структуру tm
	ptm_time = localtime(&seconds); // Системная дата
	// Если аргументы конструктора не заданы, берем системную дату
	d = dd ? dd : ptm_time->tm_mday; // Если день не задан, берется текущий день
	m = mm ? mm : ptm_time->tm_mon + 1; // Если месяц не задан, берется текущий месяц
	y = yy ? yy : ptm_time->tm_year + 1900; // Если год не задан, берется текущий год
}
