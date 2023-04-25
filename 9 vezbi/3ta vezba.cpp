#include <iostream>

using namespace std;

int main() {
    //generator za random broevi
    srand(time(0));

    //Se generira random broj od 1 do 100
    int ZamislenBroj = rand() % 100 + 1;

    int Pogodi, BrojNaPretpostavki = 0;

    cout << "Zamisliv broj od 1 do 100, potrudi se da go pogodis!" << endl;

    do {
        cout << "Vnesi go tvojot broj sto mislis deka go zamisliv: ";
        cin >> Pogodi;

        //se zgolemuva brojot na pretpostavki 
        BrojNaPretpostavki++;

        switch (Pogodi > ZamislenBroj ? 1 : Pogodi < ZamislenBroj ? -1 : 0) {
        case -1:
            cout << "Tvojot broj e so pomala vrednost, probaj povtorno!" << endl;
            break;
        case 0:
            cout << "Bravo! Go pogodi brojot! Potrebni ti bea " << BrojNaPretpostavki << " obidi." << endl;
            break;
        case 1:
            cout << "Tvojot broj e so povisoka vrednost, probaj povtorno! " << endl;
            break;
        }

    } while (Pogodi != ZamislenBroj); //se povtoruva se dodeka pogodokot e razlicen od zamisleniot broj

    return 0;
}
