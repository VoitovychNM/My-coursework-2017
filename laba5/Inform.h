#pragma once
//Inform.h

#include "Home.h"
class Inform :
	public Home
{
public:
	Inform();
	~Inform();
	void show_name();// Мета класу
	void show_menu();// Меню класу
	void ouput_general_inform();//Виводить у консоль загальну інформацію з файлу "General information.txt"
	void ouput_serviced();//Виводить на консоль можливі послуги з файлу "Service.txt"
};

