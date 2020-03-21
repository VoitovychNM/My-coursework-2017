#pragma once
//Home.h
class Home
{
public:
	Home();
	virtual void show_name() = 0;// Мета класу
	virtual void show_menu() = 0;// Меню класу
	~Home();
};

