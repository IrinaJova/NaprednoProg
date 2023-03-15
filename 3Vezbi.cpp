#include <iostream>
#include <string>

using namespace std;
//se definira enumeracija za mesecite vo godinata
enum Mesec {
    Januari,
    Fevruari,
    Mart,
    April,
    Maj,
    Juni,
    Juli,
    Avgust,
    Septemvri,
    Oktomvri,
    Noemvri,
    Dekemvri
};

int main() {
    //se deklarira niza so iminja na mesecite
    string meseci[] = {"Januari", "Fevruari", "Mart", "April", "Maj", "Juni", 
                       "Juli", "Avgust", "Septemvri", "Oktomvri", "Noemvri", "Dekemvri"};
    
    //presmetka na brojot na meseci vo nizata                   
    int broj_meseci = sizeof(meseci)/sizeof(meseci[0]);
    
    // Ispisuvanje na site meseci vo godinata
    cout << "Site meseci:" << endl;
    for(int i=0; i<broj_meseci; i++) {
        cout << meseci[i] << endl;
    }

    // Vnesuvanje na korisnikot za odreden mesec
    string vnesNa_mesec;
    cout << "Vnesete ime na mesec: ";
    cin >> vnesNa_mesec;

    // Se bara indeksot na vneseniot mesec od nizata
    Mesec izbran_mesec;
    for(int i=0; i<broj_meseci; i++) {
        if(meseci[i] == vnesNa_mesec) {
            izbran_mesec = static_cast<Mesec>(i);
            break;
        }
    }

    // Ako vneseniot mesec e validen, pecati vo koj del od godinata e i koj posledovatelen mesec e
    if(izbran_mesec >= Januari && izbran_mesec <= Dekemvri) {
        string vreme_od_godina;
        if(izbran_mesec < Mart || izbran_mesec == Dekemvri) {
            vreme_od_godina = "zima";
        } else if(izbran_mesec < Juni) {
            vreme_od_godina = "prolet";
        } else if(izbran_mesec < Septemvri) {
            vreme_od_godina = "leto";
        } else {
            vreme_od_godina = "esen";
        }

        int posledovatelen_mesec = static_cast<int>(izbran_mesec) + 1;
        cout << vnesNa_mesec << " e vo " << vreme_od_godina << " i e " 
             << posledovatelen_mesec << " posledovatelen mesec vo godinata." << endl;
    } else {
        cout << "Ne postoi takov mesec." << endl;
    }

    return 0;
}

/*Numeracijata e data-type koja se sostoi od imenuvani vrednosti kako elementi koi pretstavuvaat
integralni konstanti. Obezbeduva nacin da se definiraat i grupiraat ingernalnite konstanti i 
ima golema uloga vo toa kodot sa izgleda pomalku slozen i da bide lesen za koristenje.*/
