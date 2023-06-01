#include"Swiat.h"
#include"Czlowiek.h"
#include"Organizmy/Zwierzeta/Nag³owki/owca.h"
#include"Organizmy/Zwierzeta/Nag³owki/wilk.h"
#include"Organizmy/Zwierzeta/Nag³owki/zolw.h"
#include"Organizmy/Zwierzeta/Nag³owki/lis.h"
#include"Organizmy/Zwierzeta/Nag³owki/antylopa.h"
#include"Organizmy/Rosliny/Nag³owki/wilcze_jagody.h"
#include"Organizmy/Rosliny/Nag³owki/barszcz_sosnowskiego.h"
#include"Organizmy/Rosliny/Nag³owki/guarana.h"
#include"Organizmy/Rosliny/Nag³owki/mlecz.h"
#include"Organizmy/Rosliny/Nag³owki/trawa.h"
#include <algorithm>
#include<iostream>
#include<Windows.h>
#include <fstream>
#include <iostream>

bool porownywanie(Organizm* o1,Organizm* o2) {
	if(o1->getinicjatywa() == o2->getinicjatywa()){
		return (o1->getwiek() > o2->getwiek());
	}
	return (o1->getinicjatywa() > o2->getinicjatywa());
}

using namespace std;

Swiat::Swiat(){
}

Swiat::Swiat(int n,int m):x(n),y(m)
{
	mapa.push_back(new Czlowiek(4, 2, this));
	if (n >= 6 && m >= 6) {
		mapa.push_back(new Owca(1, 1, this));
		mapa.push_back(new Owca(1, 2, this));
		mapa.push_back(new Wilk(3, 3, this));
		
	}
	if (n >= 10 && m >= 10) {
		mapa.push_back(new Antylopa(8, 8, this));
		mapa.push_back(new Mlecz(10, 10, this));
		mapa.push_back(new Trawa(6, 6, this));
		mapa.push_back(new Zolw(8, 9, this));
	}
	if (n >= 20 && m >= 20) {
		mapa.push_back(new Barszcz_sosnowskiego(20, 20, this));
		mapa.push_back(new Guarana(12, 12, this));
		mapa.push_back(new Lis(17, 17, this));
		mapa.push_back(new Wilcze_jagody(15, 15, this));
	}
	sort(mapa.begin(), mapa.end(), porownywanie);
    
}

void Swiat::legenda() {
    gotoxy(getx() + 2, 1);
    cout << " 0 - zolw";
    gotoxy(getx() + 2, 2);
    cout << " 1 - barszcz";
    gotoxy(getx() + 2, 3);
    cout << " 2 - guarana";
    gotoxy(getx() + 2, 4);
    cout << " 3 - mlecz";
    gotoxy(getx() + 2, 5);
    cout << " 4 - trawa";
    gotoxy(getx() + 2, 6);
    cout << " 5 - wilcze_jagody";
    gotoxy(getx() + 2, 7);
    cout << " 6 - antylopa";
    gotoxy(getx() + 2, 8);
    cout << " 7 - lis";
    gotoxy(getx() + 2, 9);
    cout << " 8 - owca";
    gotoxy(getx() + 2, 10);
    cout << " 9 - wilk";
    gotoxy(getx() + 2, 11);
    cout << " X - gracz";
    gotoxy(getx() + 2, 12);
    cout << " l - load";
    gotoxy(getx() + 2, 13);
    cout << " s - save";
    gotoxy(getx() + 2, 14);
    cout << " u - umiejetnosc";
}
void Swiat::rysujswiat() {
	for (auto& element : mapa) {
		gotoxy(element->getx(), element->gety());
		element->rysowanie();
	}
}

void Swiat::wykonajture() {
	for (int i = 0; i < mapa.size(); i++) {
		if (mapa[i]->getwiek() > 0) {
			mapa[i]->Akcja();
			Sleep(1000);
		}
		else {
			mapa[i]->setwiek(1);
		}
	}
	sort(mapa.begin(), mapa.end(), porownywanie);
}

void Swiat::Rozgrywka() {
	system("cls");
    legenda();
	rysujswiat();
	while (true) {
		wykonajture();

	}
}

int Swiat::getx() {
	return x;
}

int Swiat::gety() {
	return y;
}

void Swiat::setx(int x) {
	this->x = x;
}

void Swiat::sety(int y) {
	this->y = y;
}

vector<Organizm*> Swiat::getmapa() {
	return mapa;
}

void Swiat::setmapa(vector<Organizm*> newmapa) {
	mapa = newmapa;
}

void Swiat::addorg(Organizm* neworg) {
	mapa.push_back(neworg);
}

void Swiat::load() {
    vector<Organizm*> mapatym;
    Organizm* temp = NULL;
    int swiatx, swiaty;
    int inicjatywa, sila, wiek, x, y;
    string nazwa;
    ifstream  plik("save.txt");
    if (plik.is_open()) {
        plik >> swiatx >> swiaty;

        while (plik >> inicjatywa >> sila >> wiek >> x >> y >> nazwa) {
            if (nazwa == "Barszcz_sosnowskiego") {
                temp = new Barszcz_sosnowskiego(x, y, this);
            }
            else if (nazwa == "Guarana") {
                temp = new Guarana(x, y, this);
            }
            else if (nazwa == "Mlecz") {
                temp = new Mlecz(x, y, this);
            }
            else if (nazwa == "Trawa") {
                temp = new Trawa(x, y, this);
            }
            else if (nazwa == "Wilcze_jagody") {
                temp = new Wilcze_jagody(x, y, this);
            }
            else if (nazwa == "Antylopa") {
                temp = new Antylopa(x, y, this);
            }
            else if (nazwa == "Lis") {
                temp = new Lis(x, y, this);
            }
            else if (nazwa == "Owca") {
                temp = new Owca(x, y, this);
            }
            else if (nazwa == "Wilk") {
                temp = new Wilk(x, y, this);
            }
            else if (nazwa == "Zolw") {
                temp = new Zolw(x, y, this);
            }
            else if (nazwa == "Czlowiek") {
                temp = new Czlowiek(x, y, this);
            }
            temp->setsila(sila);
            temp->setwiek(wiek);
            temp->setinicjatywa(inicjatywa);
            mapatym.push_back(temp);
        }
        this->setx(swiatx);
        this->sety(swiaty);
        this->setmapa(mapatym);
        this->Rozgrywka();
    }
    else {
        //Informacja("Nie uda³o siê otworzyæ pliku");
    }
}

Swiat::~Swiat()
{

}