#pragma once
#include"../../Zwierze.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(int, int, Swiat*);
	void Akcja();
	void rysowanie();
	std::string nazwa();
	void tworz(int, int);
	void kolizja(Organizm*, Organizm*, int, int);
	void kolizjaanty(Organizm*, Organizm*, int, int);
	~Antylopa();

private:

};

