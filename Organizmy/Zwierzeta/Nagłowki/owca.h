#pragma once
#include"../../Zwierze.h"


class Owca : public Zwierze
{
public:
	Owca(int, int, Swiat*);
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	~Owca();

private:

};

