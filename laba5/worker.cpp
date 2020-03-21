//worker.cpp

#include "Worker.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Worker::Worker()
{
}

Worker::~Worker()
{
}

void Worker::add_bilet()
{
	system("cls");

	ifstream fin;
	fin.open("Inform_tabl.txt", ios::in);

	vector<string> arr;
	string contens;
	string search;
	string line;
	char Mass[300];

	int i = 0;
	while (!fin.eof())
	{
		getline(fin, contens);

		arr.push_back(contens);

		strcpy_s(Mass, arr[i].c_str());
		int k = 0;
		while (Mass[k] != '\0')
		{
			if (Mass[k] == ',')
			{
				cout << "\t\t";
			}

			else
			{
				cout << Mass[k];
			}

			k++;
		}
		cout << endl;

		i++;
	}
	fin.close();

	int j = 0;
	int kilk_biletiv;
	int kilk_kom = 0;
	int kilk_tsyfr = 0;
	int index = 0;
	int id;
	char Line[300];

numer_poizd:
	cout << "Введiть номер поїзда: ";
	cin >> search;

	kilk_tsyfr = 0;
	id = atoi(search.c_str());
	while (id != 0)
	{
		id /= 10;
		kilk_tsyfr++;
	}

	if (kilk_tsyfr != 3)
	{
		cout << "\aВи ввели невiрнi данi!" << endl;
		goto numer_poizd;
	}





	bool flag = true;
	for (int b = 0; b < arr.size(); b++)
	{
		if (arr[b].find(search, 0) != string::npos)
		{
			system("cls");
			cout << " Номер 	              ПОЇЗД                  Вiдправл.       Прибуття        Кiлькiсть" << endl;
			cout << "поїзда                                       зi Львова      на кiнцеву     вiльних мiсць " << endl;


			strcpy_s(Line, arr[b].c_str());

			while (Line[j] != '\0')
			{
				if (Line[j] == ',')
				{
					cout << "\t\t";
					kilk_kom++;
				}

				else
				{
					cout << Line[j];
				}

				if (kilk_kom == 2 && index == 0)
				{
					index = j;
				}

				j++;
			}
			j--;

			cout << endl;

			int k = j;

			int number = 0;
			int step = 1;
			for (; index < j; j--)
			{
				number += (int(Line[j]) - 48) * step;
				step *= 10;
				Line[j] = ' ';
			}

		kilk_bilet:
			cout << "\n Введiть кiлькiсть бiлетiв котру ви хотiли додати:";
			cin >> kilk_biletiv;

			if (number < kilk_biletiv)
			{
				cout << "\aВи ввели невiрнi данi!";
				goto kilk_bilet;
			}
			else
			{
				number += kilk_biletiv;

				for (; index < k; k--)
				{
					Line[k] = number % 10 + 48;
					number /= 10;
				}
			}

			arr[b] = Line;
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\aВи ввели невiрнi данi!" << endl;
		goto numer_poizd;

	}

	ofstream fout;
	fout.open("Inform_tabl.txt");
	fout.write("", 0);

	for (i = 0; i < arr.size(); i++)
	{
		fout << arr[i] << endl;
	}
	fout.close();
	system("cls");

	cout << "\tОперацiю завершено вдало!" << endl << endl;
	cout << " 3. Повернутися до головного меню" << endl;
	cout << " 0. Вихiд з програми" << endl;
}

void Worker::prodano()
{
	ifstream fin("Prodano.txt");
	string Svmist;
	char Cvmist[10];
	int step = 1;
	int number = 0;

	fin >> Svmist;
	strcpy_s(Cvmist, Svmist.c_str());

	int i = 0;

	while (Cvmist[i] != '\0')
	{
		i++;
	}
	i--;
	for (; i >= 0; i--)
	{
		number += (int(Cvmist[i]) - 48) * step;
		step *= 10;
	}

	cout << "\t\tВсього продано " << number << " квитк" << endl << endl;

}
