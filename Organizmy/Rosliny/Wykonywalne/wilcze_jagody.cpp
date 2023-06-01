#include"../Nag³owki/wilcze_jagody.h"
#include <iostream>

Wilcze_jagody::Wilcze_jagody(int x, int y, Swiat* swiat):Roslina(x, y, 99, swiat)
{
}

void Wilcze_jagody::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
	std::vector<Organizm*> mapa = wch->getswiat()->getmapa();
	std::vector<int> dousuniecia;
	Informacja(wch->nazwa() + " zjad³ " + stoi->nazwa() + " po czym umarl");
	for (int i = 0; i < mapa.size(); i++) {
		if (mapa[i] == stoi || mapa[i] == wch) {
			dousuniecia.push_back(i);
		}
	}
	sort(dousuniecia.begin(), dousuniecia.end(), porownywanie2);
	for (int i = 0; i < dousuniecia.size(); i++) {
		mapa.erase(mapa.begin() + dousuniecia[i]);
	}
	wch->getswiat()->setmapa(mapa);
	gotoxy(wch->getx(), wch->gety());
	std::cout << " ";
}

void Wilcze_jagody::rysowanie() {
	std::cout << "5";
}

std::string Wilcze_jagody::nazwa() {
	return "Wilcze_jagody";
}

void Wilcze_jagody::tworz(int x,int y) {
	Organizm* temp = new Wilcze_jagody(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

Wilcze_jagody::~Wilcze_jagody()
{
}

