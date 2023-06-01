#include"../Nag³owki/trawa.h"
#include <iostream>

Trawa::Trawa(int x, int y, Swiat* swiat):Roslina(x, y, 0, swiat)
{
}

void Trawa::rysowanie() {
	std::cout << "4";
}

std::string Trawa::nazwa() {
	return "Trawa";
}

void Trawa::tworz(int x, int y) {
	Organizm* temp = new Trawa(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

Trawa::~Trawa()
{
}