#include"../Nag³owki/lis.h"

Lis::Lis(int x, int y, Swiat* swiat) :Zwierze(x, y, 3, 7, swiat)
{
}

void Lis::Akcja() {
    Organizm* temp;
    int tempx = getx(), tempy = gety();
    while (true) {
        Ruch(1);
        temp = Szukaj(getswiat()->getmapa(), getx(), gety(), this);
        if (temp != NULL) {
            if (temp->getsila() > getsila()) {
                setx(tempx);
                sety(tempy);
            }
            else {
                if (temp != NULL) {
                    temp->kolizja(temp, this, getx(), gety());
                }
                else {
                    gotoxy(getx(), gety());
                    rysowanie();
                }
                return;
            }
        }
        else {
            gotoxy(getx(), gety());
            rysowanie();
            return;
        }
    }
    
}

void Lis::rysowanie() {
    std::cout << "7";
}

std::string Lis::nazwa() {
    return "Lis";
}

void Lis::tworz(int x, int y) {
    Organizm* temp = new Lis(x, y, getswiat());
    temp->setwiek(0);
    getswiat()->addorg(temp);
}

Lis::~Lis()
{
}