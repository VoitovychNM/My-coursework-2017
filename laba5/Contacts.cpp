//Contacts.cpp

#include "Contacts.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Contacts::Contacts()
{
}

void Contacts::show_name()
{
	cout << "��������";
}

void Contacts::show_menu()
{
	system("cls");
	cout << "\t\t ��������" << endl;
	cout << " 1. ������ �� �������" << endl;
	cout << " 2. ���������� �����" << endl;
	cout << " 3. ����������� �����" << endl;
	cout << " 0. ���i� � ��������" << endl;

}

void Contacts::ouput_adress()
{
	ifstream fin;
	fin.open("Adress.txt", ios::in);

	system("cls");

	string contens;
	while (!fin.eof()) {
		getline(fin, contens);
		cout << contens << endl;
	}
	cout << endl << " 3. ����������� �� ��������� ����" << endl;
	cout << " 4. �����" << endl;
	cout << " 0. ���i� � ��������" << endl;
}

void Contacts::ouput_elektr_post()
{
	ifstream fin;
	fin.open("Elektr post.txt", ios::in);

	system("cls");

	string contens;
	while (!fin.eof()) {
		getline(fin, contens);
		cout << contens << endl;
	}
	cout << endl << " 3. ����������� �� ��������� ����" << endl;
	cout << " 4. �����" << endl;
	cout << " 0. ���i� � ��������" << endl;
}

Contacts::~Contacts()
{
}
