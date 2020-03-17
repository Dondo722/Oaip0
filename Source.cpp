
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct StudData 
{
	string FIO;
	string groupN;
	int mathMark;
	int chemistryMark;
	int physMark;
	int informaticsMark;
	double s_b;
};

bool check()
{
	char answ[2] = "";
	cout << " Continue / Exit(y / n)" << endl;
	cin.get(answ, 2);
	cin.ignore(INT_MAX, '\n');
	if (answ[1] == 'n')
		return false;
	else
		return true;
}// geztline trying fix

int main()
{
	ofstream outfile;
	StudData student;
	char ch;
	outfile.open("Out.txt");

	bool nextstep = true; 



	while (nextstep)        // all good; input is ok, liil fixes will be great
	{
		cout << "Name " << endl;
		cin >> student.FIO;
		cout << "Group " << endl;
		cin >> student.groupN;
		cout << "math mark " << endl;
		cin >> student.mathMark;
		cout << "chemistry mark " << endl;
		cin >> student.chemistryMark;
		cout << "physics mark " << endl;
		cin >> student.physMark;
		cout << "informatics mark " << endl;
		cin >> student.informaticsMark;

		outfile << student.FIO << " " << student.groupN << " ";
		outfile << "Математика : " << student.mathMark << " Химия : " << student.chemistryMark << " ";
		outfile << " Физика : " << student.physMark << " Информатика : " << student.informaticsMark << endl;

		cout << " Continue / Exit(y / n)" << endl;
		cin >> ch;
		if (ch == 'n')
			nextstep = false;
		else
			nextstep = true;
	}
		//cout << "Continue / Exit (y/n)" << endl;
		//cin >> ch;
	

	 //while (ch !='n');

	outfile.close();

	ifstream fin; // output i didn't tried ; need to write some algoritm
	fin.open("Out.txt");
	if (fin)
	{
		while (fin >> student.FIO >> student.groupN >> student.mathMark >> student.chemistryMark >> student.physMark >> student.informaticsMark)
		{
			cout << "Name " << student.FIO << " Group " << student.groupN;
			cout << "math mark " << student.mathMark << " chemistry mark " << student.chemistryMark;
			cout << "physics mark " << student.physMark << " informatics mark " << student.informaticsMark;
		}
		fin.close();
	}
	else
	{
		cout << "ERROR!" << endl;
	}
	cin.get();
	cin.get();
	return 0;
}


