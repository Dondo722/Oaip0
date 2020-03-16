
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
		cout << "������� ������ " << i << "-��� �������� " << endl;
		cout << "��� : ";
		cin >> students->FIO;
		cout << "������ � ";
		cin >> students->group;
		cout << "������ �� ���������� ";
		cin >> students->mathMark;
		cout << "������ �� ����� ";
		cin >> students->chemistryMark;
		cout << "������ �� ������ ";
		cin >> students->fysMark;
		cout << "������ �� ����������� ";
		cin >> students->informaticsMark;
	}
}
void show(StudData* students, int N)
{
	for (int i = 1; i < N + 1; i++)
	{
		cout << "��� :  " << students->FIO << "������ � " << students->group;
		cout << "������ �� ���������� " << students->mathMark << "������ �� ����� " << students->chemistryMark;
		cout << "������ �� ������ " << students->fysMark << "������ �� ����������� " << students->informaticsMark;

	}
}