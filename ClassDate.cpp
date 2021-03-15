#include "ClassDate.h"
#pragma warning(disable : 4996)
Date& Date:: operator=(const Date& D) // �������� ������������
{
	if (this != &D)
	{
		d = D.d; m = D.m; y = D.y;
	}
	return *this;
}
// ����������� ������ Date
Date::Date(int dd, int mm, int yy) // �������� ���������� �� ��������� ������ ��� �� �����������
{
	time_t seconds; // ���������� ��� ������
	time(&seconds); // ����� ������ �� 01.01.1970
	struct tm* ptm_time; // ��������� �� ��������� tm
	ptm_time = localtime(&seconds); // ��������� ����
	// ���� ��������� ������������ �� ������, ����� ��������� ����
	d = dd ? dd : ptm_time->tm_mday; // ���� ���� �� �����, ������� ������� ����
	m = mm ? mm : ptm_time->tm_mon + 1; // ���� ����� �� �����, ������� ������� �����
	y = yy ? yy : ptm_time->tm_year + 1900; // ���� ��� �� �����, ������� ������� ���
}
