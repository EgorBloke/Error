#include "Der_Persons.h"// (��� ���������)
#include"Der_Pers.h"



void Persons::Swap(int i, int j) // ����������� �������� i � j ������� G
{
    Pers tmp = G[i];
    G[i] = G[j];
    G[j] = tmp;
}
//���������� ������ ����������, Compare  �������� ��������� �� ������� ��������� �������� � 2� �����
void Persons::SortPersons(bool (*Compare)(const Pers&, const Pers&))     // ����� ��������
{
    for (int i = G.size() - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (!Compare(G[j], G[j + 1])) // ���� �� ��� �������,
                Swap(j, j + 1);
}    // ����������� ��������
// ���������� �������-������ ������ Persons
ostream& operator<<(ostream& os, const Persons& group) // ����� ������ ������
{
    for (int i = 0; i < group.G.size(); i++) // ����� ������
        os << group.G[i]; // � ������ ��������
    return os;
}
istream& operator>>(istream& is, Persons& group) // ������ ������ � ������ �� �����
{
    Pers tmp; // �������� � ��������
    while (!is.eof()) {
        is >> tmp; // ������ �������� � ��������
        if (is.eof()) // ���� ��������� ����� �����,
            break; // ����� �� �����
        group.Add(tmp);
    } // ���������� �������� � ������
    return is;
}
