#include"../Nag³owki/owca.h"

Owca::Owca(int x, int y, Swiat* swiat) :Zwierze(x, y, 4, 4, swiat)
{

}

Owca::~Owca()
{
}

void Owca::rysowanie() {
	std::cout << "8";
}

void Owca::tworz(int x, int y) {
	Organizm* temp = new Owca(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

std::string Owca::nazwa() {
	return "Owca";
}