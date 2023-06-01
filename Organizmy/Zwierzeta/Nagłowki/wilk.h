#pragma once
#include"../../Zwierze.h"


class Wilk : public Zwierze
{
public:
	Wilk(int, int, Swiat*);
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	~Wilk();

private:

};

