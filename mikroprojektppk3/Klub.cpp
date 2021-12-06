#include "Klub.h"


Klub::Klub(const string& nazwaPliku) : ilePilkarzy(0), nazwa("bledna nazwa"), miasto("bledne miasto"), trener(Czlowiek())
{
	ifstream stream(nazwaPliku);
	if (stream.good())
	{
		std::string line;
		getline(stream, line);
		nazwa = line;
		getline(stream, line);
		miasto = line;
		getline(stream, line);
		stringstream ss3(line);
		ss3 >> trener.imie;
		ss3 >> trener.nazwisko;
		ss3 >> trener.numerTelefonu;
		trener.rola = "trener";
		getline(stream, line);
		ilePilkarzy = atoi(line.c_str());
		for (int i = 0; i < ilePilkarzy; i++)
		{
			Pilkarz doDodania;
			stream >> doDodania;
			listaP.DodajPilkarza(doDodania);
		}
		stream.close();
	}
}

istream& operator>> (istream& stream, Pilkarz& nowy)
{
	string line;
	getline(stream, line);
	stringstream ss(line);
	ss >> nowy.imie;
	ss >> nowy.nazwisko;
	ss >> nowy.numerTelefonu;
	ss >> nowy.dataUrodzenia.rok;
	ss >> nowy.dataUrodzenia.miesiac;
	ss >> nowy.dataUrodzenia.dzien;
	ss >> nowy.numerNaKoszulce;
	ss >> nowy.pozycja.pozycjaPodstawowa;
	ss >> nowy.pozycja.pozycjaAlternatywna;
	ss >> nowy.ileBramkek;
	return stream;
}

Czlowiek::Czlowiek() : imie("Imie"), nazwisko("Nazwisko"), numerTelefonu("000000000"), rola("brak")
{

}

Pilkarz::Pilkarz()
{
	imie = "Imie";
	nazwisko = "Nazwisko";
	numerTelefonu = "0000000000";
	dataUrodzenia.rok = 1800;
	numerNaKoszulce = 0;
	pozycja.pozycjaPodstawowa = "Brak";
	pozycja.pozycjaAlternatywna = "Brak";
	ileBramkek = 0;
}

Pilkarz Pilkarz::PilkarzUstaw()
{
	cout << "Podaj imie pilkarza." << endl;
	cin >> imie;
	cout << "Podaj nazwisko pilkarza." << endl;
	cin >> nazwisko;
	cout << "Podaj numer telefonu pilkarza." << endl;
	cin >> numerTelefonu;
	cout << "Podaj rok urodzenia pilkarza." << endl;
	cin >> dataUrodzenia.rok;
	cout << "Podaj miesiac urodzenia pilkarza. (cyfra)" << endl;
	cin >> dataUrodzenia.miesiac;
	cout << "Podaj dzien urodzenia pilkarza. (cyfra)" << endl;
	cin >> dataUrodzenia.dzien;
	int pozycjanr = 0;
	while ((pozycjanr != 1) && (pozycjanr != 2) && (pozycjanr != 3) && (pozycjanr != 4))
	{
		cout << "Podaj podstawowa pozycjê pilkarza." << endl;
		cout << "1 - bramkarz" << endl;
		cout << "2 - obronca" << endl;
		cout << "3 - pomocnik" << endl;
		cout << "4 - napastnik" << endl;
		cout << "5 - brak" << endl;
		cin >> pozycjanr;
		if (pozycjanr == 1) pozycja.pozycjaPodstawowa = "Bramkarz";
		else if (pozycjanr == 2) pozycja.pozycjaPodstawowa = "Obronca";
		else if (pozycjanr == 3) pozycja.pozycjaPodstawowa = "Pomocnik";
		else if (pozycjanr == 4) pozycja.pozycjaPodstawowa = "Napastnik";
		else pozycja.pozycjaPodstawowa = "brak";
	}
	pozycjanr = 0;
	while ((pozycjanr != 1) && (pozycjanr != 2) && (pozycjanr != 3) && (pozycjanr != 4))
	{
		cout << "Podaj podstawowa pozycjê pilkarza." << endl;
		cout << "1 - bramkarz" << endl;
		cout << "2 - obronca" << endl;
		cout << "3 - pomocnik" << endl;
		cout << "4 - napastnik" << endl;
		cout << "5 - brak" << endl;
		cin >> pozycjanr;
		if (pozycjanr == 1) pozycja.pozycjaAlternatywna = "Bramkarz";
		else if (pozycjanr == 2) pozycja.pozycjaAlternatywna = "Obronca";
		else if (pozycjanr == 3) pozycja.pozycjaAlternatywna = "Pomocnik";
		else if (pozycjanr == 4) pozycja.pozycjaAlternatywna = "Napastnik";
		else pozycja.pozycjaAlternatywna = "brak";
	}
	cout << "Podaj ile bramek strzelil pilkarz." << endl;
	cin >> ileBramkek;
	return *this;
}

ListaPilkarzy::ListaPilkarzy() : pierwszy(nullptr)
{

}

void ListaPilkarzy::DodajPilkarza(Pilkarz& przekazany)
{
	ElementListyPilkarz* nowy = new ElementListyPilkarz;
	nowy->MojPilkarz = przekazany;
	if (pierwszy == nullptr)
	{
		pierwszy = nowy;
		nowy->nastepny = nullptr;
	}
	else
	{
		ElementListyPilkarz* tmp = pierwszy;
		while (tmp->nastepny)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = nowy;
		nowy->nastepny = nullptr;
	}
}

void ListaPilkarzy::WypiszPilkarzy()
{
	cout << "---------------" << endl;
	ElementListyPilkarz* tmp = pierwszy;
	while (tmp != nullptr)
	{
		cout << tmp->MojPilkarz.imie << " ";
		cout << tmp->MojPilkarz.nazwisko << endl;
		tmp = tmp->nastepny;
	}
	cout << "---------------" << endl << endl;
	return;
}

Klub::Klub() : ilePilkarzy(2), nazwa("bledna nazwa"), miasto("bledne miasto"), trener(Czlowiek())
{

}

int JakaOperacja()
{
	int czynnosc = 0;

	while ((czynnosc != 1) && (czynnosc != 2) && (czynnosc != 3) && (czynnosc != 4) && (czynnosc != 5) && (czynnosc != 9))
	{
		cout << "Wybierz :" << endl;
		cout << "1. Dodaj zawodnika do swojej listy." << endl;
		cout << "2. Znajdz i wypisz Zawodnika ze swojej listy." << endl;
		cout << "3. Usun zawodnika ze swojej listy." << endl;
		cout << "4. Wypisz najlepszych strzelcow." << endl;
		cout << "5. Wypisz od najmlodszego." << endl;
		cout << "9 . Zapisz zmiany i wyjdz." << endl;
		cin >> czynnosc;
	}
	if (czynnosc == 1) return 1;
	else if (czynnosc == 2) return 2;
	else if (czynnosc == 3) return 3;
	else if (czynnosc == 4) return 4;
	else if (czynnosc == 5) return 5;
	else if (czynnosc == 9) return 9;
	else return 0;
}

void Klub::zapiszDoPliku(const string& nazwaPliku)
{
	fstream plik;
	plik.open(nazwaPliku, ios::out);
	if (plik.good());
	{
		plik << nazwa << endl << miasto << endl;
		plik << trener.imie << " " << trener.nazwisko << " " << trener.numerTelefonu << endl;
		plik << ilePilkarzy << endl;
		ElementListyPilkarz* tmp = listaP.pierwszy;
		while (tmp != nullptr)
		{
			plik << tmp->MojPilkarz.imie << " " << tmp->MojPilkarz.nazwisko << " " << tmp->MojPilkarz.numerTelefonu << " ";
			plik << tmp->MojPilkarz.dataUrodzenia.rok << " " << tmp->MojPilkarz.dataUrodzenia.miesiac << " " << tmp->MojPilkarz.dataUrodzenia.dzien << " ";
			plik << tmp->MojPilkarz.numerNaKoszulce << " " << tmp->MojPilkarz.pozycja.pozycjaPodstawowa << " " << tmp->MojPilkarz.pozycja.pozycjaAlternatywna << " ";
			plik << tmp->MojPilkarz.ileBramkek << endl;
			ElementListyPilkarz* doUsuniecia = tmp;
			tmp = tmp->nastepny;
			delete doUsuniecia;
		}
	}
}

void Klub::ZnajdzZawodnika()
{
	ElementListyPilkarz* znalezionyPilkarz = nullptr;
	while (znalezionyPilkarz == nullptr)
	{
		string imie, nazwisko;
		cout << "Wybierz imie i nazwisko zawodnika lub wpisz wracam jesli chcesz wrocic: " << endl;
		listaP.WypiszPilkarzy();
		cout << "Podaj imie: ";
		cin >> imie;
		if (imie == "wracam")
		{
			return;
		}
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		znalezionyPilkarz = this->ZnajdzPilkarza(imie, nazwisko);


	}
	znalezionyPilkarz->WypiszPilkarza();
	return;
}

ElementListyPilkarz* Klub::ZnajdzPilkarza(const string& przekazaneImie, const string& przekazaneNazwisko)
{
	ElementListyPilkarz* tmp = listaP.pierwszy;
	while ((tmp->MojPilkarz.imie != przekazaneImie) || (tmp->MojPilkarz.nazwisko != przekazaneNazwisko))
	{
		if (tmp->nastepny == nullptr)
		{
			cout << "Nie znaleziono takiego pilkarza!" << endl;
			return nullptr;
		}
		tmp = tmp->nastepny;
	}
	return tmp;
}

void ElementListyPilkarz::WypiszPilkarza()
{
	cout << "Zawodnik ktorego szukasz:" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Imie i nazwisko, numer na koszulce: " << MojPilkarz.imie << " " << MojPilkarz.nazwisko << " " << MojPilkarz.numerNaKoszulce << endl;
	cout << "Ilosc strzelonych bramek zawodnika: " << MojPilkarz.ileBramkek << endl;
	cout << "Podstawowa pozycja:                 " << MojPilkarz.pozycja.pozycjaPodstawowa << endl;
	cout << "Alternatywna pozycja:               " << MojPilkarz.pozycja.pozycjaAlternatywna << endl;
	cout << "Data urodzenia:                     " << MojPilkarz.dataUrodzenia.rok << "-" << MojPilkarz.dataUrodzenia.miesiac << "-" << MojPilkarz.dataUrodzenia.dzien << endl;
	cout << "Numer telefonu zawodnika:           " << MojPilkarz.numerTelefonu << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}