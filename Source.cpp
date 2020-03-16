#include <iostream>
#include <stdio.h>



using namespace std;


struct students
{
	char FIO[60];
	double sball;
};

void get(students* stud);
void show(students* stud);


int main()
{
	setlocale(LC_ALL, "ru");

	students* stud = new students;
	int length = 2;

	for (int i = 0; i < length; i++)
	{
		get(stud);
		show(stud);
	}


	
	delete stud;
	return 0;
}

void get(students* stud)
{
	cout << "Введите данные о студенте " << endl;
	cout << "ФИО:" << endl;
	cin >> stud->FIO;
	cout << "средний балл :" << endl;
	cin >> stud->sball;
}
void show(students* stud)
{
	cout << "ФИО студента : " << stud->FIO << "\tсредний балл :" << stud->sball <<endl;
}