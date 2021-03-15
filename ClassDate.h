#ifndef ClassDateH
#define ClassDateH
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Date { // ����� ��� ������ � ������
	int d, m, y; // ����, �����, ���
public:
	Date(int  dd = 0, int  mm = 0, int  yy = 0);   // �����������
	Date(const Date& D) // ����������� �����������
	{
		d = D.d; m = D.m; y = D.y;
	}
	Date& operator=(const Date& D);// �������� ������������
	bool operator<=(const Date& D) const // ��������� ���� ���
	// ����� const � ���������  ��������, ��� ��� �� �������� ������ ������ ��� �������� ����������
	{
		return (y < D.y) || (y == D.y && m < D.m) || (y == D.y && m == D.m && d <= D.d);
	}
	friend ostream& operator<<(ostream& os, const Date& dt)// ����� ����
	{
		return os << setw(2) << setfill('0') << dt.d << '.' << setw(2) << setfill('0') << dt.m << '.' << dt.y << endl;
	}
	friend istream& operator>>(istream& is, Date& dt)// ���� ����
	{
		return is >> dt.d >> dt.m >> dt.y;
	}
};

#endif

