#include"Zwierze.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

enum kierunki {
    gora = 1,
    dol = 2,
    prawo = 3,
    lewo = 4  
};

void Zwierze::Akcja() {
    int tempx = getx(), tempy = gety();
    Ruch(1);
    setwiek(getwiek() + 1);
    gotoxy(getx(), gety());
    rysowanie();
    CzyPoleZejete(this, tempx, tempy);
}

void Zwierze::Ruch(int pola) {
    srand(time(NULL));
    gotoxy(getx(), gety());
    std::cout << " ";
    int dobryruch = 0;
    while (dobryruch == 0) {
        int ruch = 1 + rand() % 4;
        switch (ruch) {
        case gora: {
            if (gety() - pola >= 1) {
                sety(gety() - pola);
                dobryruch++;
            }
            break;
        }
        case dol: {
            if (gety() + pola <= getswiat()->gety()) {
                sety(gety() + pola);
                dobryruch++;
            }
            break;
        }
        case prawo: {
            if (getx() + pola <= getswiat()->getx()) {
                setx(getx() + pola);
                dobryruch++;
            }
            break;
        }
        case lewo: {
            if (getx() - pola >= 1) {
                setx(getx() - pola);
                dobryruch++;
            }
            break;
        }
        }
    }

    setwiek(getwiek() + 1);
}

void Zwierze::kolizja(Organizm* stoi,Organizm* wch,int x, int y) {
    if (typeid(*stoi) == typeid(*wch)) {
        wch->setx(x);
        wch->sety(y);
        gotoxy(x, y);
        rysowanie();
        if (y + 1 <= stoi->getswiat()->gety()) {
            Organizm* temp = Szukaj(getswiat()->getmapa(), x, y+1, NULL);
            if (temp == NULL) {
                Informacja("Narodziny " + wch->nazwa());
                tworz(x, y+1);
                gotoxy(x, y + 1);
                rysowanie();
            }
        }
    }
    else {
        Organizm::kolizja(stoi, wch, x, y);
    }
}

Zwierze::Zwierze(int x,int y,int inicjatywa,int sila, Swiat* swiat):Organizm(x, y, sila, swiat) {
	
	this->setinicjatywa(inicjatywa);
}

bool Zwierze::czyroslina() {
    return false;
}

Zwierze::Zwierze() {

}

Zwierze::~Zwierze() {

}