#pragma once
#include"Organizm.h"
#include <iostream>

class Swiat;

class Zwierze: public Organizm
{
public:
	Zwierze();
	Zwierze(int, int, int, int, Swiat*);
	bool czyroslina();
	void Akcja();
	void Ruch(int);
	void kolizja(Organizm*, Organizm*, int, int);
	~Zwierze();
private:

};