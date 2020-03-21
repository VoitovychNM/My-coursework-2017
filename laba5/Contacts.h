//Contacts.h
#pragma once
#include "Home.h"
class Contacts :
	public Home
{
public:
	Contacts();
	void show_name();// Мета класу
	void show_menu();// Меню класу
	void ouput_adress();// Виводить на консоль адресу
	void ouput_elektr_post();// Виводить на консоль електронну пошту
	~Contacts();
};

#pragma once
