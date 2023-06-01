#include"Organizm.h"
#include <iostream>
#include <string>

Organizm::Organizm(int x,int y,int sila,Swiat* swiat) : x(x), y(y), sila(sila), wiek(), inicjatywa(),swiat(swiat)
{
}

Organizm::Organizm() : x(), y(), sila(), wiek(1), inicjatywa(), swiat(swiat)
{
}

Organizm::~Organizm()
{
}

void Organizm::Akcja()
{
}

int Organizm::getx()
{
	return x;
}

Swiat* Organizm::getswiat() {
	return swiat;
}

int Organizm::gety()
{
	return y;
}

int Organizm::getsila()
{
	return sila;
}

int Organizm::getinicjatywa()
{
	return inicjatywa;
}

void Organizm::setx(int x)
{
	this->x = x;
}

void Organizm::sety(int y)
{
	this->y = y;
}

void Organizm::setsila(int sila)
{
	this->sila = sila;
}

void Organizm::setinicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

void Organizm::setwiek(int wiek)
{
	this->wiek = wiek;
}

int Organizm::getwiek() {
	return wiek;
}

void Organizm::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
		std::vector<Organizm*> mapa = wch->getswiat()->getmapa();
		std::vector<int> dousuniecia;
		if (stoi->getsila() > wch->getsila()) {
			Informacja(stoi->nazwa() + " zjad³ " + wch->nazwa());
			for (int i = 0; i < mapa.size(); i++) {
				if (mapa[i] == wch) {
					dousuniecia.push_back(i);
				}
			}
			sort(dousuniecia.begin(), dousuniecia.end(), porownywanie2);
			for (int i = 0; i < dousuniecia.size(); i++) {
				mapa.erase(mapa.begin() + dousuniecia[i]);
			}
			gotoxy(getx(), gety());
			stoi->rysowanie();
			stoi->getswiat()->setmapa(mapa);
		}
		else {
			Informacja(wch->nazwa() + " zjad³ " + stoi->nazwa());
			for (int i = 0; i < mapa.size(); i++) {
				if ( mapa[i] == stoi) {
					dousuniecia.push_back(i);
				}
			}
			sort(dousuniecia.begin(), dousuniecia.end(), porownywanie2);
			for (int i = 0; i < dousuniecia.size(); i++) {
				mapa.erase(mapa.begin() + dousuniecia[i]);
			}
			gotoxy(getx(), gety());
			wch->rysowanie();
			wch->getswiat()->setmapa(mapa);
		}
}

Organizm* Organizm::Szukaj(std::vector<Organizm*> arr, int x, int y, Organizm* to) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i]->getx() == x && arr[i]->gety() == y && arr[i] != to) {
			return arr[i];
		}
	}
	return NULL;
}

void Organizm::Informacja(std::string str) {
	gotoxy(getswiat()->getx()+2, 16);
	std::cout << str << "                                    ";
}

void Organizm::CzyPoleZejete(Organizm* org,int x,int y) {
	Organizm* temp = Szukaj(getswiat()->getmapa(), getx(), gety(), org);
	if (temp != NULL) {
		temp->kolizja(temp, this, x, y);
	}
}