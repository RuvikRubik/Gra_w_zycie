#include"../Nag³owki/zolw.h"

Zolw::Zolw(int x, int y, Swiat* swiat) :Zwierze(x, y, 2, 1, swiat)
{
}

void Zolw::Akcja() {
	srand(time(NULL));
	int tempx = getx(), tempy = gety();
	int ruch = 1 + rand() % 4;
	if (ruch == 1) {
		Ruch(1);
		CzyPoleZejete(this, tempx, tempy);
		gotoxy(getx(), gety());
		rysowanie();
	}
}

void Zolw::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
	if (typeid(*stoi) == typeid(*wch)) {
		Informacja("Narodziny " + wch->nazwa());
		wch->setx(x);
		wch->sety(y);
	}
	else {
		if (wch->getsila() < 5) {
			Informacja(stoi->nazwa() + " odpar³ " + wch->nazwa());
			wch->setx(x);
			wch->sety(y);
		}
		else {
			Zwierze::kolizja(stoi, wch, x, y);
		}
	}
	
}

void Zolw::rysowanie() {
	std::cout << "0";
}

std::string Zolw::nazwa() {
	return "Zolw";
}

void Zolw::tworz(int x, int y) {
	Organizm* temp = new Zolw(x, y, getswiat());
	temp->setwiek(0);
	getswiat()->addorg(temp);
}

Zolw::~Zolw()
{
}