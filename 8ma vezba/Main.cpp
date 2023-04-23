#define _CRT_SECURE_NO_WARNINGS //davase warning za local time
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

bool ProverkaNaOdgovor(int BrojNaPrasanje, string odgovor) { //proverka dali dadeniot odgovor od korisnikot  e tocen
	//se zemaat dva argumenti: BrojNaPrasanje i odgovor
	if (BrojNaPrasanje == 1 && odgovor == "c") {
		return true;
	}
	else if (BrojNaPrasanje == 2 && odgovor == "a") {
		return true;
	}
	else if (BrojNaPrasanje == 3 && odgovor == "c") {
		return true;
	}
	else if (BrojNaPrasanje == 4 && odgovor == "a") {
		return true;
	}
	else if (BrojNaPrasanje == 5 && odgovor == "b") {
		return true;
	}
	else if (BrojNaPrasanje == 6 && odgovor == "b") {
		return true;
	}
	else if (BrojNaPrasanje == 7 && odgovor == "c") {
		return true;
	}
	else if (BrojNaPrasanje == 8 && odgovor == "b") {
		return true;
	}
	else if (BrojNaPrasanje == 9 && odgovor == "c") {
		return true;
	}
	else if (BrojNaPrasanje == 10 && odgovor == "b") {
		return true;
	}
	else if (BrojNaPrasanje == 11 && odgovor == "c") {
		return true;
	}
	else if (BrojNaPrasanje == 12 && odgovor == "a") {
		return true;
	}
	else { //ako ne e daden tocen odgovor return false;
		return false;
	}
}

int PresmetkaNaOcena(int bodovi) { //presmetka na bodovite vo zavisnost od tocnite odgovori
	if (bodovi < 61) {
		return 5; //dobienata ocenka
	}
	else if (bodovi < 71) {
		return 6;
	}
	else if (bodovi < 81) {
		return 7;
	}
	else if (bodovi < 91) {
		return 8;
	}
	else if (bodovi < 111) {
		return 9;
	}
	else {
		return 10;
	}
}

void ZapisuvanjeNaRezultat(string Ime, string Prezime, string Indeks, string PocetokNaVreme, string ZavrsnoVreme) { //
	ofstream rezultati("rezultati.txt", ios::app); //zapis na rezultatite vo rezultati.txt 
	if (rezultati.is_open()) {
		rezultati << "Pocetno vreme: " << PocetokNaVreme << endl;
		rezultati << "Ime: " << Ime << endl;
		rezultati << "Prezime: " << Prezime << endl;
		rezultati << "Indeks: " << Indeks << endl;
		rezultati << "Zavrsno vreme: " << ZavrsnoVreme << endl;
		rezultati << endl;
		rezultati.close();
	}
	else {
		cout << "Otvaranjeto na fajlot ne e uspesno" << endl;
	}
}

int main() {
	string Ime, Prezime, Indeks;
	bool postoi = false;
	int bodovi = 0;
	cout << "Vnesi ime: " << endl;
	getline(cin, Ime);
	cout << "Vnesi prezime: " << endl;
	getline(cin, Prezime);
	cout << "Vnesi indeks: " << endl;
	getline(cin, Indeks); 
	string ImeNaFajl = Ime + "_" + Prezime + "_" + Indeks + ".txt";

	ifstream infile(ImeNaFajl.c_str()); //proverka dali veke go ima resavano testot
	if (infile.good()) {
		postoi = true;
		cout << "Veke ste gi odgovorile prasanjata, nemate pravo na uste eden obid!!" << endl;
		return 0;
	}

	auto now = chrono::system_clock::now();
	time_t PocetokNaVreme = chrono::system_clock::to_time_t(now); //zapis na pocetok na resavanje na testot

	ifstream Prasanja ("Prasanja.txt"); //otvoranje na prasanjata za korisnikot
	if (Prasanja.is_open()) {
		string prasanje, odgovor;
		int BrojNaPrasanje = 1;
		ofstream outfile(ImeNaFajl.c_str(), ios_base::app);
		while (getline(Prasanja, prasanje)) {
			cout << prasanje << endl;
			getline(cin, odgovor);
			if (ProverkaNaOdgovor(BrojNaPrasanje, odgovor)) { //proverka na tocen odgovor vo zavisnost od prasanjeto sto se odgovara vo momentot

				bodovi += 10; //poeni za tocen odgovor
			}
			outfile << "Odgovor: "<<odgovor << endl;
			BrojNaPrasanje++; //se odi na naredno prasanje
		}
	}
	else {
		cout << "Fajlot ne mozi da se otvori!" << endl;
		return 1;
	}

	now = chrono::system_clock::now();
	time_t ZavrsnoVreme = chrono::system_clock::to_time_t(now); //vreme koga se zavrsil testot

	cout << " Imate osvoeno: " << bodovi << " bodovi" << endl;
	cout << " Spored toa vasata ocenka e: " << PresmetkaNaOcena(bodovi) << endl;
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", localtime(&PocetokNaVreme)); //postavuvanje na format na izgled na vremeto i datumot i konvertiranje na vremeto vo string
	string PocetokNaVremeStr = buffer;
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", localtime(&ZavrsnoVreme));
	string ZavrsnoVremeStr = buffer;

	ofstream outfile(ImeNaFajl.c_str(), ios_base::app); //zapis na podatocite za sekoj korisnik posebno
	outfile << "Vreme na zapocnuvanje na testot: " << PocetokNaVremeStr << endl;
	outfile << "******************************************************************" << endl;
	outfile << "Ime:" << Ime << endl; 
	outfile << "Prezime: " << Prezime << endl;
	outfile << "Indeks: " << Indeks << endl;
	outfile << "Bodovi: " << bodovi << endl;
	outfile << "Ocenka: " << PresmetkaNaOcena(bodovi) << endl;
	outfile << "******************************************************************" << endl;
	outfile << "Vreme na zavrsuvanje na testot: " << ZavrsnoVremeStr << endl;
	outfile.close();

	ZapisuvanjeNaRezultat(Ime, Prezime, Indeks, PocetokNaVremeStr, ZavrsnoVremeStr); //ispisuvanje na rezultati od korisnik
	
	
	return 0;


}