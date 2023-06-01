#pragma once
#include"Organizmy/Zwierze.h"
class Czlowiek: public Zwierze
{
public:
	Czlowiek(int,int, Swiat*);
	void rysowanie();
	std::string nazwa();
	void tworz(int, int);
	void kolizja(Organizm*, Organizm*, int, int);
	int Ruchczl();
	void Akcja();
	void save();
	~Czlowiek();

private:
	bool umiejetnosc = false;
	int czastrw=0, czasodn=0;
};
