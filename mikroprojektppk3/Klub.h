#pragma once
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <list>
#include <fstream>
#include <vector>
#include <utility> 
#include <memory>
#include <windows.h>
#include <winbase.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;


class PozycjaNaBoisku
{
public:
	std::string pozycjaPodstawowa;
	std::string pozycjaAlternatywna;
};

class Czlowiek
{
public:
	std::string imie;
	std::string nazwisko;
	std::string numerTelefonu;
	std::string rola;
	Czlowiek();
};

class Data
{
public:
	int dzien;
	int miesiac;
	int rok;
};

class Pilkarz : public Czlowiek
{
public:
	Data dataUrodzenia;
	int numerNaKoszulce;
	PozycjaNaBoisku pozycja;
	int ileBramkek;
	Pilkarz();
	Pilkarz PilkarzUstaw();
	friend istream& operator>> (istream& strumien, Pilkarz& nowy);
};

class ElementListyPilkarz
{
public:
	Pilkarz MojPilkarz;
	ElementListyPilkarz* nastepny;
	ElementListyPilkarz* pierwszy;
	void WypiszPilkarza();
};

class ListaPilkarzy
{
public:
	ElementListyPilkarz* pierwszy;
	ListaPilkarzy();
	void DodajPilkarza(Pilkarz&);
	void WypiszPilkarzy();
};

class Klub
{
public:
	std::string nazwa;
	std::string miasto;
	int ilePilkarzy;
	ListaPilkarzy listaP;
	Czlowiek trener;
	Klub();
	Klub(const std::string&);
	Klub(ifstream&);
	void zapiszDoPliku(const string&);
	void ZnajdzZawodnika();
	ElementListyPilkarz* ZnajdzPilkarza(const string&, const string&);
};

int JakaOperacja();