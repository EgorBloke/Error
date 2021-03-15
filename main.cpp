#include "Der_Persons.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Persons Writers; // Writers � ������ ������ Persons
	ifstream inf("PersData.txt"); // ������� �������� �����
	if (!inf) { // ���� ���� �� ������� �������,
		cerr << "�� ������� ������� ���� PersData.txt ";
		exit(1); // ��������� ���������
	}
	inf >> Writers; // ������ �� �����
	cout << "������ ������: \n";
	cout << Writers << endl; // ����� ������� ������
	// ���������� �� ����������� ���� ��������
	Writers.SortPersons(CmpDate);
	cout << "������ ������ �� ����������� ����: \n";
	cout << Writers << endl;
	// ���������� � ���������� �������
	Writers.SortPersons(CmpName);
	cout << "������ ������ �� ��������: \n";
	cout << Writers << endl;
	system("pause");
	return 0;
}
