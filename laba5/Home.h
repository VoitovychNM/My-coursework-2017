#pragma once
//Home.h
class Home
{
public:
	Home();
	virtual void show_name() = 0;// ���� �����
	virtual void show_menu() = 0;// ���� �����
	~Home();
};

