#include <iostream>
#include <string>
#include <fstream>

using namespace std;





int main() 
{
	setlocale(LC_ALL, "ru");

	ofstream file;

	cout << " Выберите , что вы хотите сделать:\n 1)Создание \n 2)Просмотр \n 3)Коррекцию ";
	int choise;
	cin >> choise;
	switch (choise)
	{
	case 1:
		cout << " Введите имя файла .txt";
		string filename;
		cin >> filename;
		file.open(filename);
		break;
	}



	//file.open("Stud_Data.txt", ofstream::app);

	if (!file.is_open())
	{
		cout << "Ошибка при открытии файла";
	}
	else 
	{
		cout << " Выберите , что вы хотите сделать:\n 1)Создание \n 2)Просмотр \n 3)Коррекцию ";
	}


	return 0;
}