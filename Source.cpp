
#include <iostream>

using namespace std;

struct StudData 
{
	static const int N = 255;
	char FIO[N] = "";
	char group[N] = "";
	int mathMark;
	int chemistryMark;
	int fysMark;
	int informaticsMark;
	double s_b;
};

void get(StudData* students, int N);
void show(StudData* students, int N);

int main()
{
	setlocale(LC_ALL, "ru");

	int N = 5;
	StudData* students = new StudData[N];
	get(students, N);
	show(students, N);



	return 0;
}
void get(StudData* students, int N)
{
	for (int i = 1; i < N+1; i++)
	{
		cout << "Введите данные " << i << "-ого студента " << endl;
		cout << "ФИО : ";
		cin >> students->FIO;
		cout << "группа № ";
		cin >> students->group;
		cout << "Оценка по математике ";
		cin >> students->mathMark;
		cout << "Оценка по химии ";
		cin >> students->chemistryMark;
		cout << "Оценка по физике ";
		cin >> students->fysMark;
		cout << "Оценка по информатике ";
		cin >> students->informaticsMark;
	}
}
void show(StudData* students, int N)
{
	for (int i = 1; i < N + 1; i++)
	{
		cout << "ФИО :  " << students->FIO << "группа № " << students->group;
		cout << "Оценка по математике " << students->mathMark << "Оценка по химии " << students->chemistryMark;
		cout << "Оценка по физике " << students->fysMark << "Оценка по информатике " << students->informaticsMark;

	}
}