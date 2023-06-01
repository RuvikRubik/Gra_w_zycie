#include"Swiat.h"
#include<iostream>
using namespace std;

int main() {
	int x, y;
	cout << "Podaj wielkosc swiata:";
	cin >> x;
	cin >> y;
	Swiat* swiat = new Swiat(x,y);
	swiat->Rozgrywka();
	return 1;
}




////testowy
//int main() {
//	vector<int> wektor;
//
//	for (int i = 0; i < 10; ++i)
//		wektor.push_back(i);
//
//	for (int i = 0; i < wektor.size(); ++i) {
//		if (i == 4) {
//			wektor.erase(wektor.begin() + i);
//		}
//		cout << wektor[i] << ' ';
//	}
//		
//}