#include "Der_Persons.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Persons Writers; // Writers – объект класса Persons
	ifstream inf("PersData.txt"); // Входной файловый поток
	if (!inf) { // Если файл не удалось открыть,
		cerr << "Не удалось открыть файл PersData.txt ";
		exit(1); // завершаем программу
	}
	inf >> Writers; // Чтение из файла
	cout << "Состав группы: \n";
	cout << Writers << endl; // Вывод состава группы
	// Сортировка по возрастанию даты рождения
	Writers.SortPersons(CmpDate);
	cout << "Состав группы по возрастанию даты: \n";
	cout << Writers << endl;
	// Сортировка в алфавитном порядке
	Writers.SortPersons(CmpName);
	cout << "Состав группы по алфавиту: \n";
	cout << Writers << endl;
	system("pause");
	return 0;
}
