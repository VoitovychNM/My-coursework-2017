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
	cout << "����i�� ����� �����: ";
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
		cout << "\a�� ����� ���i��i ���i!" << endl;
		goto numer_poizd;
	}





	bool flag = true;
	for (int b = 0; b < arr.size(); b++)
	{
		if (arr[b].find(search, 0) != string::npos)
		{
			system("cls");
			cout << " ����� 	              �ί��                  �i������.       ��������        �i���i���" << endl;
			cout << "�����                                       �i ������      �� �i�����     �i����� �i��� " << endl;


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
			cout << "\n ����i�� �i���i��� �i���i� ����� �� ���i�� ������:";
			cin >> kilk_biletiv;

			if (number < kilk_biletiv)
			{
				cout << "\a�� ����� ���i��i ���i!";
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
		cout << "\a�� ����� ���i��i ���i!" << endl;
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

	cout << "\t������i� ��������� �����!" << endl << endl;
	cout << " 3. ����������� �� ��������� ����" << endl;
	cout << " 0. ���i� � ��������" << endl;
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

	cout << "\t\t������ ������� " << number << " �����" << endl << endl;

}
