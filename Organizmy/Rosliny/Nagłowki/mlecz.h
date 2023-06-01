#pragma once
#include"../../Roslina.h"

class Mlecz : public Roslina
{
public:
	Mlecz(int, int, Swiat*);
	void rysowanie();
	void Akcja();
	void tworz(int, int);
	std::string nazwa();
	~Mlecz();

private:

};
