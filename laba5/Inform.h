#pragma once
//Inform.h

#include "Home.h"
class Inform :
	public Home
{
public:
	Inform();
	~Inform();
	void show_name();// ���� �����
	void show_menu();// ���� �����
	void ouput_general_inform();//�������� � ������� �������� ���������� � ����� "General information.txt"
	void ouput_serviced();//�������� �� ������� ������ ������� � ����� "Service.txt"
};

