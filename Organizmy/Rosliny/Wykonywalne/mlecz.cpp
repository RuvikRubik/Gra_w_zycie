#include"../Nag³owki/mlecz.h"
#include <iostream>

Mlecz::Mlecz(int x, int y, Swiat* swiat):Roslina(x, y, 0, swiat)
{
}

void Mlecz::rysowanie() {
	std::cout << "3";
}

std::string Mlecz::nazwa() {
	return "Mlecz";
}

void Mlecz::Akcja() {
	rozprzestrzenianie();
	rozprzestrzenianie();
	rozprzestrzenianie();
}

void Mlecz::tworz(int x, int y) {
	Organizm* temp = new Mlecz(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

Mlecz::~Mlecz()
{
}