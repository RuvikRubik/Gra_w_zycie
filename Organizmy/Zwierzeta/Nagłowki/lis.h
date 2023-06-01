#pragma once
#include"../../Zwierze.h"


class Lis : public Zwierze
{
public:
	Lis(int, int, Swiat*);
	void Akcja();
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	~Lis();

private:

};

