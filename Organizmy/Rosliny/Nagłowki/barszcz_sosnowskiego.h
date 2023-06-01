#pragma once
#include"../../Roslina.h"

class Barszcz_sosnowskiego : public Roslina
{
public:
	Barszcz_sosnowskiego(int, int, Swiat*);
	void kolizja(Organizm*, Organizm*, int, int);
	void Akcja();
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	~Barszcz_sosnowskiego();

private:

};

