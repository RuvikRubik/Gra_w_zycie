#pragma once
#include"Organizm.h"

class Roslina : public Organizm
{
public:
	Roslina();
	Roslina(int, int, int, Swiat*);
	void kolizja(Organizm*, Organizm*,int,int);
	void rozprzestrzenianie();
	bool czyroslina();
	void Akcja();
	~Roslina();

private:

};
