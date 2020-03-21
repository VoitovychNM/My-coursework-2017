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
	cout << "Iнформацiя";
}

void Inform::show_menu()
{
	system("cls");
	cout << "\t\t Iнформацiя" << endl;
	cout << " 1. Загальна iнформацiя" << endl;
	cout << " 2. Послуги" << endl;
	cout << " 3. Повернутися назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
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
	cout << endl << " 3. Повернутися до головного меню" << endl;
	cout << " 4. Назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
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
	cout << endl << " 3. Повернутися до головного меню" << endl;
	cout << " 4. Назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
}

Inform::~Inform()
{
}
