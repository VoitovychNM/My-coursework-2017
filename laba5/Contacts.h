//Contacts.h
#pragma once
#include "Home.h"
class Contacts :
	public Home
{
public:
	Contacts();
	void show_name();// ���� �����
	void show_menu();// ���� �����
	void ouput_adress();// �������� �� ������� ������
	void ouput_elektr_post();// �������� �� ������� ���������� �����
	~Contacts();
};

#pragma once
