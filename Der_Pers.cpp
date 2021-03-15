#include "Der_Pers.h"
// ���������� �������-����� ������ Pers

Pers& Pers::operator=(const Pers& ps) // �������� ������������
{
	if (this != &ps) { // ���� ������������ �� ������ ����,
		name = ps.name; // ����������� �����,
		Date::operator=(ps); //����������� ���� (������ ������������ ����: d = ps.d;m = ps.m;y = ps.y;�����������)
	}     // �������� ����������� ���� this->Date::operator=(ps);
	return *this; // ����������� ������ �� ������
}
// ���� ������ �� ����� ��������
istream& operator>>(istream& is, Pers& ps)
{
	is >> (Date&)ps; // ���� ���� ��������
 // ������ �� ������ ps ���� Pers ���������� � ���� ������ �� Date
	getline(is, ps.name); // ���� ������� � ����� (���������)
	// ����� ������� ������� ������������� ������� � ������ � ��������
	int indexNotSpaceTab = ps.name.find_first_not_of(" \t");
	// �������� ��������� ��������
	ps.name = ps.name.substr(indexNotSpaceTab, ps.name.length());
	return is;
}
bool CmpDate(const Pers& ps1, const Pers& ps2)
{
	return ps1 <= ps2;
}        // ������������ �������-�������� ��������� ���
// CmpName: ��������� �������
bool CmpName(const Pers& ps1, const Pers& ps2) // CmpName: ��������� �������
{
	return ps1.name <= ps2.name;
}