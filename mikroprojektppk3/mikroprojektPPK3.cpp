#include "Klub.h"
#include <iostream>

int main()
{
	Klub WczytanyKlub("Klub.txt");
	cout << "Nazwa klubu: " << WczytanyKlub.nazwa << endl << "Miasto klubu: " << WczytanyKlub.miasto << endl;
	cout << "Pilkarzy w klubie: " << WczytanyKlub.ilePilkarzy << endl;

	int numerOperacji = 0;
	while (numerOperacji != 9)
	{
		numerOperacji = JakaOperacja();
		if (numerOperacji == 1)
		{
			Pilkarz	nowyPilkarz;
			nowyPilkarz.PilkarzUstaw();
			WczytanyKlub.listaP.DodajPilkarza(nowyPilkarz);
		}
		if (numerOperacji == 2)
		{
			WczytanyKlub.ZnajdzZawodnika();
		}
	}

	WczytanyKlub.zapiszDoPliku("Klub.txt");
}
