#ifndef Der_PersH
#define Der_PersH
#include "ClassDate.h"
class Pers;

bool CmpDate(const Pers& ps1, const Pers& ps2);

bool CmpName(const Pers& ps1, const Pers& ps2);

class Pers : public Date 
{
	string name; 
	Pers(const string& nm, const Date& D) : Date(D), name(nm) // ����������� � �����������
	{ }
	Pers() : Date(), name() 
	{ } // ������ ������ ��� ���
	Pers(const Pers& ps) : Date(ps), name(ps.name) // ����������� �����������
	{ }
	Pers& operator = (const Pers&); // �������� ������������
	friend ostream& operator<<(ostream& os, const Pers& ps) // ����� �������� � ��������
	{
		return os << ps.name << "     \t" << Date(ps);
	}
	friend istream& operator>>(istream& is, Pers& ps); // �������� ����� �������� � ��������
	// CmpDate: ���������� true, ���� ���� ������� ps1  ����� ������ ��� �� ��, ��� � � ������� ps2
	friend bool CmpDate(const Pers& ps1, const Pers& ps2);
// CmpName: ��������� �������
	friend bool CmpName(const Pers& ps1, const Pers& ps2); // CmpName: ��������� �������
};

#endif
