#pragma once
//Timetable.h
#pragma once
#include "Home.h"
class Timetable :
	public Home
{
	int kilk_prodanych_biletiv;
public:
	Timetable();
	void show_name();// Мета класу
	void show_menu();// Меню класу
	void ouput_tariff();// Метод виводить на екран тариф з файлу "Tariff.txt"
	void inform_tabl();// Метод виводить інформаційне табло на екран
	double price_men(int n);// Метод обраховує ціну
	double price_children(int n);// Метод обраховує ціну на дитячі квитки
	double price_stydent(int n);// Метод обраховує ціну для студентів
	~Timetable();
};



