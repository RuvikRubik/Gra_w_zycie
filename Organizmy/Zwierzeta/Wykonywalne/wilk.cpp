#include"../Nag³owki/wilk.h"

Wilk::Wilk(int x, int y, Swiat* swiat) :Zwierze(x, y, 9, 5, swiat)
{

}

Wilk::~Wilk()
{
}

std::string Wilk::nazwa() {
	return "Wilk";
}

void Wilk::tworz(int x, int y) {
	Organizm* temp = new Wilk(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

void Wilk::rysowanie() {
	std::cout << "9";
}