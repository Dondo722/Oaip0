#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int length = 100;

struct Data_ab_Stud
{
	char fname[30] = "NULL";
	char lname[30] = "NULL";
	int group = 1;
	int math = 9;
    int chemistry = 10;
	int physics = 8;
	int informatics = 4;
	double s_b(int math, int chemistry, int physics, int informatics)
	{
		double a;
		a = ((double)math + (double)chemistry + (double)physics + (double)informatics)/4;
		return a;
	}
	void print(Data_ab_Stud* stud, int i)
	{
		cout << "Name: " << stud[i].fname <<" "<< stud[i].lname << " " << "Group: " << stud[i].group << " ";
		cout << "\nmath: " << stud[i].math << "\nphysics: " << stud[i].physics;
		cout << "\nchemistry: " << stud[i].chemistry << "\ninformatics: " << stud[i].informatics;
		cout << "\nS_b: " << stud[i].s_b(stud[i].math, stud[i].chemistry, stud[i].physics, stud[i].informatics) << endl;
		cout << "------------" << endl;
	}
	void print()
	{
		cout << "Name: " << fname <<" "<< lname << " " << "Group: " << group << " ";
		cout << "\nmath: " << math << "\nphysics: " << physics;
		cout << "\nchemistry: " << chemistry << "\ninformatics: " << informatics;
		cout << "\nS_b: " << s_b(math, chemistry, physics, informatics) << endl;
		cout << "------------" << endl;
	}
};

int main()
{
	string path = "result.txt";
	string s,name,str;
	char  xfname[30],xlname[30];
	int n = 1, i , ch, grp, Sb, llgth = 0;
	Data_ab_Stud* stud = new Data_ab_Stud [length] ;
	Data_ab_Stud rst;
	ofstream rez,zap;
	ifstream fin;
	fstream redact;
	streampos pos1;
	rez.open(path, ios:: app);
	while (true)
	{
		cout << "1)Create \n2)Add \n3)View \n4)find \n5)redact \n0)exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			rez.close();
			cout << " file zapis.txt successfully created " << endl;
			rez.close();
			rez.open(path);
			rez.close();
			break;
		case 2:
			rez.close();
			zap.open(path, ios::binary | ios::app);
			if (!zap.is_open())
			{
				cout << "Open error!";
			}
			else
			{

				for (i = 0; i < length; i++)
				{

					cout << "Name " << endl;
					cin >> stud[i].fname >> stud[i].lname;
					cout << "Group " << endl;
					cin >> stud[i].group;
					cout << "math, physics,chemistry, informatics marks " << endl;
					cin >> stud[i].math >> stud[i].physics >> stud[i].chemistry >> stud[i].informatics;

					zap.write((char*)&stud[i], sizeof(Data_ab_Stud));
					break;
				}
			}
			zap.close();

			break;
		case 3:
			fin.open(path, ios::binary);
			if (!fin.is_open())
			{
				cout << "Open Error!" << endl;
			}
			else
			{
				while (fin.read((char*)&rst, sizeof(Data_ab_Stud)))
				{
					rst.print();
				}
			}
			fin.close();
			break;
		case 4:
			fin.open(path, ios::binary);
			cout << "group number :" << endl;
			cin >> grp;
			cout << "average mark :" << endl;
			cin >> Sb;
			for (int i = 0; i < 1; i++)
			{
				while (fin.read((char*)&rst, sizeof(Data_ab_Stud)))
				{
					stud[i] = rst;
					if (stud[i].group == grp && stud[i].s_b(stud[i].math, stud[i].chemistry, stud[i].physics, stud[i].informatics) > Sb)
					{
						stud[i].print(stud, i);
					}
				}
			}
			fin.close();
			break;
		case 5:
			cout << "Student Name :" << endl;
			cin >> xfname >> xlname;

			redact.open(path, ios::app | ios::in | ios::out);
			for (int i = 0; i < 1; i++)
			{
				while (redact.read((char*)&rst, sizeof(Data_ab_Stud)))
				{
					stud[i] = rst;
					i++;
				}
			}
			for (int i = 0; i < length; i++)
			{

					if (strcmp(stud[i].fname, xfname) == 0 && strcmp(stud[i].lname, xlname) == 0)
					{
						stud[i].print();
						cout << "new data" << endl;
						cout << "Name " << endl;
						cin >> stud[i].fname >> stud[i].lname;
						cout << "Group " << endl;
						cin >> stud[i].group;
						cout << "math, physics,chemistry, informatics marks " << endl;
						cin >> stud[i].math >> stud[i].physics >> stud[i].chemistry >> stud[i].informatics;
						cout << "changed student data: " << endl;
						stud[i].print();
						break;
					}
			}
			redact.close();
			zap.open(path, ios::binary);
			for ( i = 0; i < length; i++)
			{
				if (strcmp(stud[i].fname, "NULL") == 0)
					break;

				zap.write((char*)&stud[i], sizeof(Data_ab_Stud));
			}
			zap.close();
			break;
		case 0:
			rez.close();
			return 1;
		}
	}
}


