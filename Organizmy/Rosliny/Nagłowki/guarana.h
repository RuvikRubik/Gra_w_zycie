#pragma once
#include"../../Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(int, int, Swiat*);
	void kolizja(Organizm*, Organizm*, int, int);
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	~Guarana();

private:

};

