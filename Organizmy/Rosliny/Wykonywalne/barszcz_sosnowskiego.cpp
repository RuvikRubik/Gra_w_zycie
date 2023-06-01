#include"../Nag³owki/barszcz_sosnowskiego.h"
#include <iostream>

Barszcz_sosnowskiego::Barszcz_sosnowskiego(int x, int y, Swiat* swiat):Roslina(x, y, 10, swiat)
{
}

void Barszcz_sosnowskiego::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
	std::vector<Organizm*> mapa = getswiat()->getmapa();
	std::vector<int> dousuniecia;
	Informacja(wch->nazwa() + " zjad³ " + stoi->nazwa() + " po czym umarl");
	for (int i = 0; i < mapa.size(); i++) {
		if (mapa[i] == stoi || mapa[i]  == wch) {
			dousuniecia.push_back(i);
		}
	}
	sort(dousuniecia.begin(), dousuniecia.end(), porownywanie2);
	for (int i = 0; i < dousuniecia.size(); i++) {
		mapa.erase(mapa.begin() + dousuniecia[i]);
	}
	getswiat()->setmapa(mapa);
	gotoxy(wch->getx(), wch->gety());
	std::cout << " ";
}

void Barszcz_sosnowskiego::Akcja() {
	int barszczx = getx();
	int barszczy = gety();
	std::vector<Organizm*> mapa = getswiat()->getmapa();
	std::vector<int> dousuniecia;
	for (int i = 0; i < mapa.size(); i++) {
		if ((mapa[i]->getx() == barszczx - 1 && mapa[i]->gety() == barszczy) || (mapa[i]->getx() == barszczx + 1 && mapa[i]->gety() == barszczy) || (mapa[i]->getx() == barszczx && mapa[i]->gety() == barszczy - 1) || (mapa[i]->getx() == barszczx && mapa[i]->gety() == barszczy + 1)) {
			Informacja(nazwa() + " zabi³ " + mapa[i]->nazwa());
			gotoxy(mapa[i]->getx(), mapa[i]->gety());
			std::cout << " ";
			dousuniecia.push_back(i);
		}
	}
	sort(dousuniecia.begin(), dousuniecia.end(), porownywanie2);
	for (int i = 0; i < dousuniecia.size(); i++) {
		mapa.erase(mapa.begin() + dousuniecia[i]);
	}
	getswiat()->setmapa(mapa);
}

void Barszcz_sosnowskiego::rysowanie() {
	std::cout << "1";
}

std::string Barszcz_sosnowskiego::nazwa() {
	return "Barszcz_sosnowskiego";
}

void Barszcz_sosnowskiego::tworz(int x, int y) {
	Organizm* temp = new Barszcz_sosnowskiego(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

Barszcz_sosnowskiego::~Barszcz_sosnowskiego()
{
}