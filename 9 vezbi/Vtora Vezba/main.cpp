#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string ImeNaFajl, tekst;

    cout << "Vnesete go imeto na fajlot: ";
    cin >> ImeNaFajl;

    cout << "Vnesete tekst sto sakate da bide zapisan vo fajlot: ";
    cin.ignore(); //se ignorira znakot za nova linija koj e ostaven vo vlezniot buffer
    getline(cin, tekst);

    //proverka dali fajlot postoi
    ifstream infile(ImeNaFajl); 
    bool postoi = infile.good(); //good() vraka true ako postoi 
    infile.close();

    char izbor{};
    if (postoi) {
        cout << "Fajlot veke postoi. Dali sakate da prezapisete nesto ili da dodadete postoecka datoteka?? (D/F): ";
        cin >> izbor;
    }

    ofstream outfile;
    if (izbor == 'D' || !postoi) {
        //ako korisnikot odbira da prezapise ili datotekata ne postoi, se orvara datoteka vo standarden nacin (rezim)
        outfile.open(ImeNaFajl);
    }
    else if (izbor == 'F') {
        //ako korisnikot izbere da dodade, se otvara fajlot so rezim na dodavanje na sodrzina vo postoecka sodrzina
        outfile.open(ImeNaFajl, ios_base::app);
    }
    else {
        cout << "Nevaliden izbor, programata prekinuva." << endl;
        return 0;
    }

    if (outfile.is_open()) {
        outfile << tekst << endl;
        cout << "Tekstot e zapisan vo fajlot." << endl;
        outfile.close();
    }
    else {
        cout << "Greska vo otvoranjeto na fajlot." << endl;
    }

    return 0;
}

   

