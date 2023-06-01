#pragma once
#include <cstddef>
#include<string>
#include"Funkcje.h"
#include <algorithm>
#include "../Swiat.h"

class Swiat;

class Organizm
{

public:
	Organizm();
	Organizm(int, int, int, Swiat*);
	~Organizm();
	virtual void Akcja();
	virtual void kolizja(Organizm*, Organizm*, int, int);
	virtual void rysowanie() = 0;
	virtual std::string nazwa() = 0;
	virtual bool czyroslina() = 0;
	virtual void tworz(int, int) = 0;
	int getx();
	int gety();
	int getsila();
	int getinicjatywa();
	int getwiek();
	void Informacja(std::string);
	Organizm* Szukaj(std::vector<Organizm*>, int, int, Organizm*);
	void CzyPoleZejete(Organizm*,int,int);
	Swiat* getswiat();
	void setx(int);
	void sety(int);
	void setsila(int);
	void setinicjatywa(int);
	void setwiek(int);
private:
	int sila,inicjatywa,x,y,wiek;
	Swiat* swiat;
};



