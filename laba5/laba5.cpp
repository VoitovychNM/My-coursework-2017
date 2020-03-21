
#include <iostream>
#include <fstream>
#include <string>
#include "Home.h"
#include "Timetable.h"
#include "Contacts.h"
#include "Inform.h"
#include "Worker.h"

using namespace std;

void menu(Home* arr[]);
int get_step();

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	Home* arr[3];

	Inform informatiom;
	Timetable timetab;
	Contacts contact;
	Worker worker;

	arr[0] = &timetab;
	arr[1] = &contact;
	arr[2] = &informatiom;

menu:
	cout << "1. Клiєнт" << endl;
	cout << "2. Працiвник" << endl;
	cout << "0. Вийти" << endl;

	int n;
	n = get_step();

	if (n == 1)
	{
		while (true)
		{
			system("cls");
			menu(arr);
			int step;
			step = get_step();

			switch (step)
			{

			case 0:
				return 0;

			case 1:
			case_1:
				arr[0]->show_menu();
				step = get_step();

				if (step == 1)
				{
					timetab.inform_tabl();
					step = get_step();


				}

				else if (step == 2)
				{
					timetab.ouput_tariff();
					step = get_step();
				}

				if (step == 3)
				{
					continue;
				}

				if (step == 4)
				{
					goto case_1;
				}

				if (step == 0)
				{
					return 0;
				}

				else
				{
					cout << "\aВи ввели невiрнi данi!" << endl;
					system("pause");
					goto case_1;
				}

				break;


			case 2:
			case_2:
				arr[1]->show_menu();
				step = get_step();

				if (step == 1)
				{
					contact.ouput_adress();
					step = get_step();
				}

				else if (step == 2)
				{
					contact.ouput_elektr_post();
					step = get_step();
				}

				if (step == 3)
				{
					continue;
				}

				if (step == 4)
				{
					goto case_2;
				}

				if (step == 0)
				{
					return 0;
				}

				else
				{
					cout << "\aВи ввели невiрнi данi!" << endl;
					system("pause");
					goto case_2;
				}

				break;


			case 3:
			case_3:
				arr[2]->show_menu();
				step = get_step();

				if (step == 1)
				{
					informatiom.ouput_general_inform();
					step = get_step();
				}

				else if (step == 2)
				{
					informatiom.ouput_general_inform();
					step = get_step();
				}

				if (step == 3)
				{
					continue;
				}

				if (step == 4)
				{
					goto case_3;
				}

				if (step == 0)
				{
					return 0;
				}

				else
				{
					cout << "\aВи ввели невiрнi данi!" << endl;
					system("pause");
					goto case_3;
				}

				break;

			default:
				cout << "\aВи ввели невiрнi данi!" << endl;
				system("pause");
				break;
				{

				}
			}
		}
	}

	if (n == 2)
	{
		string password;
		cout << "Введiть пароль: "; cin >> password;
		if (password != "admin")
		{
			cout << "Ви ввели невiрнi данi!" << endl;
			cout << "Введiть 0 для виходу" << endl;
			system("pause");
			return 0;
		}

	worker:
		system("cls");
		cout << "1. Переглянути кiлькiсть проданих квиткiв" << endl;
		cout << "2. Додати квитки" << endl;
		int f = get_step();

		if (f == 1)
		{
			system("cls");
			worker.prodano();
			cout << " 3. Повернутися до головного меню" << endl;
			cout << " 0. Вихiд з програми" << endl;
			f = get_step();
		}
		if (f == 2)
		{
			system("cls");
			worker.add_bilet();
			f = get_step();
		}
		if (f == 3)
		{
			goto worker;
		}
		if (f == 0)
		{
			return 0;
		}
	}

	if (n == 0)
	{
		return 0;
	}

	else
	{
		system("cls");
		cout << "Ви ввели невiрнi данi!" << endl;
		goto menu;
	}

	return 0;
}


void menu(Home* arr[])
{
	cout << "\t\tЗалiзничний вокзал" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << ' ' << i + 1 << ". ";
		arr[i]->show_name();
		cout << endl;
	}
	cout << " 0. Вихiд з програми " << endl;
}

int get_step()
{
	int n;
	cout << "Введiть цифру вiдповiдно до пункту: "; cin >> n;
	return n;
}