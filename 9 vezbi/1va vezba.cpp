#include <iostream>
#include <string>

using namespace std;

int main() {

    int dolzina, BrojGolemiBukvi = 0, BrojMaliBukvi = 0, BrojCifri = 0, BrojSpecijalniZnaci = 0;
    string recenica;

    cout << "Vnesete recenica: ";
    getline(cin, recenica);

    dolzina = recenica.length();

    //Se prelistuva niz site karakteri (znaci) vo recenicata
   
    for (int i = 0; i < dolzina; i++) {
        char c = recenica[i];
       
        if (isupper(c)) {
            BrojGolemiBukvi++;
        }
        else if (islower(c)) {
            BrojMaliBukvi++;
        }
        else if (isdigit(c)) {
            BrojCifri++;
        }
        else {
            BrojSpecijalniZnaci++;
        }
    }
    

    cout << "Vo recenicata ima :" << endl;
    cout << BrojGolemiBukvi << " golemi bukvi" << endl;
    cout << BrojMaliBukvi << " mali bukvi " << endl;
    cout << BrojCifri << " broevi" << endl;
    cout << BrojSpecijalniZnaci << " specijalni znaci" << endl;
    cout << "Recenicata ima " << dolzina << " vkupno karakteri." << endl;

    return 0;
}
