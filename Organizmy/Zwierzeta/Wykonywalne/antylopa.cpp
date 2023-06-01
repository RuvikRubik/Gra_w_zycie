#include"../Nag³owki/antylopa.h"

Antylopa::Antylopa(int x, int y, Swiat* swiat) :Zwierze(x, y, 4, 4, swiat)
{
}

void Antylopa::Akcja() {
    int tempx = getx(), tempy = gety();
    Ruch(2);
    Organizm* temp = Szukaj(getswiat()->getmapa(), getx(), gety(), this);
    if (temp != NULL) {
        kolizjaanty(temp, this, tempx, tempy);
    }
    else {
        gotoxy(getx(), gety());
        rysowanie();
    }
}

void Antylopa::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
    kolizjaanty(stoi, wch, x, y);
}

void Antylopa::kolizjaanty(Organizm* stoi,Organizm* wch, int x, int y) {
    if (stoi->czyroslina() == false) {
        if (typeid(*wch) == typeid(*stoi)) {
            Informacja("Narodziny " + wch->nazwa());
            wch->setx(x);
            wch->sety(y);
            gotoxy(getx(), gety());
            rysowanie();
        }
        else {
            srand(time(NULL));
            int ruch = 1 + rand() % 2;
            if (ruch == 1) {
                stoi->kolizja(stoi, wch, x, y);
            }
            else {
                Informacja(nazwa() + " Uciekl");
                if (typeid(*stoi) == typeid(Antylopa)) {
                    stoi->setx(x);
                    stoi->sety(y);
                }
                else {
                    wch->setx(x);
                    wch->sety(y);
                }
                
                gotoxy(getx(), gety());
                rysowanie();              
            }
        }
    }
    else {
        stoi->kolizja(stoi, wch, x, y);
    }
}

void Antylopa::rysowanie() {
    std::cout << "6";
}

std::string Antylopa::nazwa() {
    return "Antylopa";
}

void Antylopa::tworz(int x, int y) {
    Organizm* temp = new Antylopa(x, y, getswiat());
    temp->setwiek(0);
    getswiat()->addorg(temp);
}

Antylopa::~Antylopa()
{
}