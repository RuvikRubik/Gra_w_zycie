#include"Roslina.h"
#include <time.h>

Roslina::Roslina() {

}

Roslina::Roslina(int x, int y, int sila, Swiat* swiat) :Organizm(x, y, sila, swiat)
{
	setinicjatywa(0);
}


void Roslina::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
	std::vector<Organizm*> mapa = wch->getswiat()->getmapa();
	std::vector<int> dousuniecia;

	Informacja(stoi->nazwa() + " zjad³ " + wch->nazwa());
	for (int i = 0; i < mapa.size(); i++) {
		if (mapa[i] == stoi) {
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

bool Roslina::czyroslina() {
	return true;
}

void Roslina::rozprzestrzenianie() {
	srand(time(NULL));
	int pole = -1 + rand() % 3; {
		if (pole != 0) {
			if (getx() + pole >= 1 && getx() + pole <= getswiat()->getx() && gety() + pole >= 1 && gety() + pole <= getswiat()->gety()) {
				Organizm* temp = Szukaj(getswiat()->getmapa(), getx() + pole, gety() + pole, NULL);
				if (temp == NULL) {
					Informacja("Rozsiano nowe " + nazwa());
					tworz(getx() + pole, gety() + pole);
					gotoxy(getx() + pole, gety() + pole);
					rysowanie();
				}
				
			}
		}
	}
}

void Roslina::Akcja() {
	rozprzestrzenianie();
	setwiek(getwiek()+1);
}

Roslina::~Roslina()
{
}