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
	void show_name();// ���� �����
	void show_menu();// ���� �����
	void ouput_tariff();// ����� �������� �� ����� ����� � ����� "Tariff.txt"
	void inform_tabl();// ����� �������� ������������ ����� �� �����
	double price_men(int n);// ����� �������� ����
	double price_children(int n);// ����� �������� ���� �� ������ ������
	double price_stydent(int n);// ����� �������� ���� ��� ��������
	~Timetable();
};



