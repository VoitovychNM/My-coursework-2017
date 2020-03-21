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
	cout << "Контакти";
}

void Contacts::show_menu()
{
	system("cls");
	cout << "\t\t Контакти" << endl;
	cout << " 1. Адреса та талефон" << endl;
	cout << " 2. Електронна пошта" << endl;
	cout << " 3. Повернутися назад" << endl;
	cout << " 0. Вихiд з програми" << endl;

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
	cout << endl << " 3. Повернутися до головного меню" << endl;
	cout << " 4. Назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
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
	cout << endl << " 3. Повернутися до головного меню" << endl;
	cout << " 4. Назад" << endl;
	cout << " 0. Вихiд з програми" << endl;
}

Contacts::~Contacts()
{
}
