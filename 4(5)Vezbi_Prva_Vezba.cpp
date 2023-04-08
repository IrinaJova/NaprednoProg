#include <iostream>
#include <string>

using namespace std;

string Ime[1];
string Prezime[1];
//funkcija za promena na prvite 4 karakteri od imeto
string menuvanjeNaimeto(string imeto) {
    string promenetoime = imeto;
    if (imeto.length() >= 4) { //proverka dali dolzinata na imeto e barem 4 bukvi
        promenetoime[0] = '?';
        promenetoime[1] = '<';
        promenetoime[2] = '!';
        promenetoime[3] = '$';
    }
    return promenetoime;
}
//funkcija za promena na prvite 4 karakteri od prezimeto
string menuvanjeNaprezimeto(string prezimeto) {
    string promenetoprezime = prezimeto;
    if (prezimeto.length() >= 4) { //proverka dali dolzinata na prezimeto e barem 4 bukvi
        promenetoprezime[0] = '>';
        promenetoprezime[1] = '_';
        promenetoprezime[2] = '<';
        promenetoprezime[3] = '*';
    }
    return promenetoprezime;
}

int main() {
    Ime[0] = "Irina";
    Prezime[0] = "Jovanoska";

    cout << "Originalnoto ime: " << Ime[0] <<endl;
    cout << "Originalnoto prezime: " << Prezime[0] << endl;

    string promenetoIme = menuvanjeNaimeto(Ime[0]);
    string promenetoPrezime = menuvanjeNaprezimeto(Prezime[0]);
    cout << "Promeneto ime: " << promenetoIme <<endl;
    cout<<"Promeneto prezime: "  << promenetoPrezime << endl;

    return 0;
}
