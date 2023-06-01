#pragma once
#include"../../Zwierze.h"

class Zolw : public Zwierze
{
public:
	Zolw(int, int, Swiat*);
	void Akcja();
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	void kolizja(Organizm*, Organizm*, int, int);
	~Zolw();

private:

};

