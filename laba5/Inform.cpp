//Inform.cpp
#include "Inform.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Inform::Inform()
{
}

void Inform::show_name()
{
	cout << "I�������i�";
}

void Inform::show_menu()
{
	system("cls");
	cout << "\t\t I�������i�" << endl;
	cout << " 1. �������� i�������i�" << endl;
	cout << " 2. �������" << endl;
	cout << " 3. ����������� �����" << endl;
	cout << " 0. ���i� � ��������" << endl;
}

void Inform::ouput_general_inform()
{
	ifstream fin;
	fin.open("General infomation.txt", ios::in);

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

void Inform::ouput_serviced()
{
	ifstream fin;
	fin.open("Service.txt", ios::in);

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

Inform::~Inform()
{
}
