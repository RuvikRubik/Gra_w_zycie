#include"../Nag³owki/guarana.h"
#include <iostream>

Guarana::Guarana(int x, int y, Swiat* swiat):Roslina(x, y, 0, swiat)
{
}

void Guarana::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
	std::vector<Organizm*> mapa = wch->getswiat()->getmapa();
	std::vector<int> dousuniecia;
	Informacja(wch->nazwa() + " zjad³ " + stoi->nazwa() + " otrzymal 3 do sily");
	wch->setsila(wch->getsila() + 3);
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
	wch->rysowanie();
}

void Guarana::rysowanie() {
	std::cout << "2";
}

std::string Guarana::nazwa() {
	return "Guarana";
}

void Guarana::tworz(int x, int y) {
	Organizm* temp = new Guarana(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

Guarana::~Guarana()
{
}