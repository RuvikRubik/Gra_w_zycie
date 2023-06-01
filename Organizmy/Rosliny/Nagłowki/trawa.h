#pragma once
#include"../../Roslina.h"

class Trawa : public Roslina
{
public:
	Trawa(int, int, Swiat*);
	void rysowanie();
	void tworz(int, int);
	std::string nazwa();
	~Trawa();

private:

};

