#ifndef Der_PersonsH
#define Der_PersonsH
#include "Der_Pers.h" // ����������� ������ Pers
class Persons // ����� ��� ������ � ������� ���
{
    vector<Pers> G; // ������ �������� � �����
public:
    void Add(const Pers& pd) // ���������� �������� � ������ ������ ��������
    {
        G.push_back(pd);
    }
    // ���������� �� ��������, ����������� �������� ��������� Compare()
    //���������� ������� ����������  �������� ��������� Compare �� �������, 
    //������� ���������� ������ �������� ���� ����� (�� ����� ��� ����)
    void SortPersons(bool (*Compare)(const Pers&, const Pers&));
    // ����� �������� � ������ ���
    friend ostream& operator<<(ostream&, const Persons&);
    // ���� �������� � ������ ���
    friend istream& operator>>(istream&, Persons&);
private:
    void Swap(int i, int j); // �������� ������� �������� i � j ������� G
};
#endif
