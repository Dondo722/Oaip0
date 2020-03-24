#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

struct Data_ab_Stud
{
	char fio[30];
	char group[30];
	int math;
    int chemistry;
	int physics;
	int informatics;
	double s_b(int math, int chemistry, int physics, int informatics)
	{
		double a;
		a = ((double)math + (double)chemistry + (double)physics + (double)informatics)/4;
		return a;
	}
	void print()
	{
		cout << "Name: "<<fio << " "<<"Group: " << group << " ";
		cout << "\nmath: " << math << "\nphysics: " << physics;
		cout << "\nchemistry: " << chemistry << "\ninformatics: " << informatics;
		cout << "\nS_b: " << s_b(math, chemistry, physics, informatics) << endl;
		cout << "------------" << endl;

	}
};

int main()
{
	string path2 = "zapis.txt";
	string path = "result.txt";
	int n = 1,mrk;
	Data_ab_Stud* stud = new Data_ab_Stud ;
	Data_ab_Stud st;
	int ch;
	ofstream rez,zap;
	ifstream fin;
	rez.open(path, ios:: app);
	while (true)
	{
		cout << "1)Create \n2)Add \n3)file zapis \n4)file result \n5)exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			rez.close();
			rez.open(path2);
			cout << " file zapis.txt successfully created " << endl;
			rez.close();
			rez.open(path);
			rez.close();
			break;
		case 2:
			rez.close();
			cout << "Choose a mark" << endl;
			cin >> mrk;
			zap.open(path2, ios_base::app);
			if (!zap.is_open())
			{
				cout << "Open error!";
			}
			else
			{
			
				for (int i = 0; i < n; i++)
				{

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Name " << endl;
					cin.getline(stud[i].fio, 30);
					cout << "Group " << endl;
					cin >> stud[i].group;
					cout << "math, physics,chemistry, informatics marks " << endl;
					cin >> stud[i].math >> stud[i].physics >> stud[i].chemistry >> stud[i].informatics;

					zap.write((char*)&stud[i], sizeof(Data_ab_Stud));

					if (stud[i].s_b(stud[i].math, stud[i].chemistry, stud[i].physics, stud[i].informatics) > mrk)
					{
						rez.open(path, ios_base::app);
						rez.write((char*)&stud[i], sizeof(Data_ab_Stud));
						rez.close();
					}
				}
			}
			zap.close();
			break;
		case 3:
			fin.open(path2, ios_base::in);
			if (!fin.is_open())
			{
				cout << "Open Error!" << endl;
			}
			else
			{
				while (fin.read((char*)&st, sizeof(Data_ab_Stud)))
				{
					st.print();
				}

			}
			fin.close();
			break;
		case 4:
			fin.open(path);
			if (!fin.is_open())
			{
				cout << "Open Error!" << endl;
			}
			else
			{
				while (fin.read((char*)&st, sizeof(Data_ab_Stud)))
				{
					st.print();
				}

			}
			fin.close();
			break;
		case 0:
			return false;
		}
	}
	rez.close();
	return 0;
}


