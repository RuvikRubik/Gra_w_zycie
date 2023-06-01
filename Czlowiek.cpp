#include"Czlowiek.h"
#include <conio.h>
#include <fstream>
using namespace std;

enum kierunki {
    gora = 72,
    dol = 80,
    lewo = 75,
    prawo = 77
};



Czlowiek::Czlowiek(int x,int y, Swiat* swiat):Zwierze(x, y, 5, 4,swiat)
{
	
}

Czlowiek::~Czlowiek()
{
}


void Czlowiek::rysowanie() {
	std::cout << "X";
}

void Czlowiek::Akcja() {
    int przycisk;
    int tempx = getx(), tempy = gety();
    int dobryruch = 0;
    while (dobryruch == 0) {
        if ((przycisk =_getch()) == 224) {
            dobryruch = Ruchczl();
        }
        else if(przycisk == 117){
            if (czasodn == 0) {
                Informacja("Uruchiomiono super umiejetnosc");
                czastrw = 5;
                umiejetnosc = true;
            }
            else {
                Informacja("Umiejetnosc niezaladowana trzeba poczekac " + czasodn);
            }
        }
        else if (przycisk == 115) {
            save();
        }
        else if (przycisk == 108) {
            this->getswiat()->load();
        }
    }
    czastrw--;
    if (czastrw == 0) {
        Informacja("super umiejetnosc wygasla");
        czasodn = 5;
    }
    gotoxy(tempx, tempy);
    cout << " ";
    gotoxy(getx(), gety());
    rysowanie();
    setwiek(getwiek() + 1);
    CzyPoleZejete(this, tempx, tempy);
}

void Czlowiek::kolizja(Organizm* stoi, Organizm* wch, int x, int y) {
    if (umiejetnosc == true) {
        wch->setx(x);
        wch->sety(y);
        Informacja("Przy pomocy super umiejetnosci odparles atak");
    }
    else {
        Zwierze::kolizja(stoi,wch,x,y);
    }
}

std::string Czlowiek::nazwa() {
    return "Czlowiek";
}

int Czlowiek::Ruchczl() {
    int dobryruch = 0;
    {
        switch (_getch()) {
        case gora:
            if (gety() - 1 < 1) {
                Informacja("Nie mo¿na wyjœæ z mapy");
            }
            else {
                sety(gety() - 1);
                dobryruch++;
            }
            break;
        case dol:
            if (gety() + 1 > getswiat()->gety()) {
                Informacja("Nie mo¿na wyjœæ z mapy");
            }
            else {
                sety(gety() + 1);
                dobryruch++;
            }
            break;
        case prawo:
            if (getx() + 1 > getswiat()->getx()) {
                Informacja("Nie mo¿na wyjœæ z mapy");
            }
            else {
                setx(getx() + 1);
                dobryruch++;
            }
            break;
        case lewo:
            if (getx() - 1 < 1) {
                Informacja("Nie mo¿na wyjœæ z mapy");
            }
            else {
                setx(getx() - 1);
                dobryruch++;
            }
            break;
        }
        return dobryruch;
    }
}

void Czlowiek::tworz(int x, int y) {

}

void Czlowiek::save() {
    vector<Organizm*> mapa = getswiat()->getmapa();
    ofstream plik("save.txt");
    if (plik.is_open()) {
        string str = "";
        str = to_string(getswiat()->getx()) + " " + to_string(getswiat()->gety()) + "\n";
        plik << str;
        for (int i = 0; i < mapa.size(); i++) {
            plik << to_string(mapa[i]->getinicjatywa()) + " ";
            plik << to_string(mapa[i]->getsila()) + " ";
            plik << to_string(mapa[i]->getwiek()) + " ";
            plik << to_string(mapa[i]->getx()) + " ";
            plik << to_string(mapa[i]->gety()) + " ";
            plik << mapa[i]->nazwa() + "\n";
        }
        Informacja("Zapisano gre");
        plik.close();
    }
    else {
        Informacja("Nie uda³o siê otworzyæ pliku");
    }
}

