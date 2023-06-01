#pragma once
#include"../../Roslina.h"

class Wilcze_jagody : public Roslina
{
public:
	Wilcze_jagody(int, int, Swiat*);
	void kolizja(Organizm*, Organizm*, int, int);
	void rysowanie();
	void tworz(int,int);
	std::string nazwa();
	~Wilcze_jagody();

private:

};

