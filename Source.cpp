#include <iostream>
#include <string>
#include <fstream>

using namespace std;





int main() 
{
	setlocale(LC_ALL, "ru");

	ofstream file;

	cout << " �������� , ��� �� ������ �������:\n 1)�������� \n 2)�������� \n 3)��������� ";
	int choise;
	cin >> choise;
	switch (choise)
	{
	case 1:
		cout << " ������� ��� ����� .txt";
		string filename;
		cin >> filename;
		file.open(filename);
		break;
	}



	//file.open("Stud_Data.txt", ofstream::app);

	if (!file.is_open())
	{
		cout << "������ ��� �������� �����";
	}
	else 
	{
		cout << " �������� , ��� �� ������ �������:\n 1)�������� \n 2)�������� \n 3)��������� ";
	}


	return 0;
}