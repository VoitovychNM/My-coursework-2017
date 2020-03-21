//Timetable.cpp

#include "Timetable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Timetable::Timetable()
{
	kilk_prodanych_biletiv = 0;
}

void Timetable::show_name()
{
	cout << "Розклад";
}

void Timetable::show_menu()
{
	system("cls");
	cout << "\t\t Розклад" << endl;
	cout << " 1. Iнформацiйне табло" << endl;
	cout << " 2. Тарифи" << endl;
	cout << " 3. Повернутися назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
}

double Timetable::price_men(int n)
{
	if (n <= 40)
	{
		return 5;
	}
	else
		if (n > 40 && n <= 70)
		{
			return 8.50;
		}
		else
			if (n > 70 && n <= 100)
			{
				return 12;
			}
			else
				if (n > 100 && n <= 130)
				{
					return 12.60;
				}
				else
					if (n > 130 && n <= 170)
					{
						return 16.10;
					}
					else
						if (n > 170 && n <= 200)
						{
							return 19.80;
						}
						else
							if (n > 200 && n <= 300)
							{
								return 24.40;
							}
							else
							{
								return n * 1.20;
							}
}

double Timetable::price_children(int n)
{
	if (n <= 40)
	{
		return 4;
	}
	else
		if (n > 40 && n <= 70)
		{
			return 6.50;
		}
		else
			if (n > 70 && n <= 100)
			{
				return 10;
			}
			else
				if (n > 100 && n <= 130)
				{
					return 10.60;
				}
				else
					if (n > 130 && n <= 170)
					{
						return 14.10;
					}
					else
						if (n > 170 && n <= 200)
						{
							return 17.80;
						}
						else
							if (n > 200 && n <= 300)
							{
								return 22.40;
							}
							else
							{
								return n * 1;
							}
}

double Timetable::price_stydent(int n)
{
	if (n <= 40)
	{
		return 2.50;
	}
	else
		if (n > 40 && n <= 70)
		{
			return 4.25;
		}
		else
			if (n > 70 && n <= 100)
			{
				return 6;
			}
			else
				if (n > 100 && n <= 130)
				{
					return 6.30;
				}
				else
					if (n > 130 && n <= 170)
					{
						return 8.50;
					}
					else
						if (n > 170 && n <= 200)
						{
							return 9.90;
						}
						else
							if (n > 200 && n <= 300)
							{
								return 12.20;
							}
							else
							{
								return n * 0.6;
							}
}

void Timetable::ouput_tariff()
{
	ifstream fin;
	fin.open("Tariff.txt", ios::in);

	system("cls");

	string contens;
	while (!fin.eof()) {
		getline(fin, contens);
		cout << contens << endl;
	}
	cout << endl << " 3. Повернутися до головного меню" << endl;
	cout << " 4. Назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
}

void Timetable::inform_tabl()
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
	int kilk_biletiv_kypyty;
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
			cout << "\n Введiть кiлькiсть бiлетiв яку б ви хотiли купити:";
			cin >> kilk_biletiv_kypyty;

			if (number < kilk_biletiv_kypyty)
			{
				cout << "\aВи ввели невiрнi данi!";
				goto kilk_bilet;
			}
			else
			{
				number -= kilk_biletiv_kypyty;
				kilk_prodanych_biletiv += kilk_biletiv_kypyty;
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
		fout << arr[i];
		if (i + 1 != arr.size())
		{
			fout << endl;
		}
	}
	fout.close();

	system("cls");

	ifstream in("Prodano.txt");
	string Svmist;
	char Cvmist[100];
	int step = 1;
	int number = 0;

	in >> Svmist;
	strcpy_s(Cvmist, Svmist.c_str());

	i = 0;

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

	kilk_prodanych_biletiv += number;

	ofstream out;
	out.open("Prodano.txt");
	out.write("", 0);

	out << kilk_prodanych_biletiv;
	out.close();


	cout << "\tОперацiю завершено вдало!" << endl << endl;
	cout << "Виберiть цифру вiдповiдно дiї:" << endl;
	cout << " 3. Повернутися до головного меню" << endl;
	cout << " 4. Назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
}

Timetable::~Timetable()
{
}

