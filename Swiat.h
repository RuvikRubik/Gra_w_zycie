#pragma once
//#include"Organizmy/Zwierzeta/Nag³owki/owca.h"
#include<vector>

class Organizm;

class Swiat
{
private:
	std::vector<Organizm*> mapa;
	int x, y;
public:
	Swiat();
	Swiat(int,int);
	void Rozgrywka();
	~Swiat();
	void wykonajture();
	void rysujswiat();
	int getx();
	int gety();
	void setx(int);
	void sety(int);
	void load();
	void legenda();
	std::vector<Organizm*> getmapa();
	void addorg(Organizm*);
	void setmapa(std::vector<Organizm*>);
};

