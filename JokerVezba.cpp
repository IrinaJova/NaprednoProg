//INKI1053
#include <iostream>
#include <array>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    //Inicijalizacija na spil so karti
    array<string, 54> deck;
    string suits[] = {"\x03", "\x05", "\x04", "\06"};
    string ranks[] = {"ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    //Se dodavaat kartite vo spilot
    int card_count = 0;
    for (int i = 0; i < 4; i++) { //pominuvanje niz znacite
        for (int j = 0; j < 13; j++) { //pominuvanje niz vrednostite
            deck[card_count] = ranks[j] + " " + suits[i]; //se dodava kartata na spilot
            card_count++;
        }
    }

    //Dodavanje na 2 dzokeri vo spilot
    deck[52] = "Joker";
    deck[53] = "Joker";

    // Prikazuvanje na kartite kako sto se po red
    cout << "Neizmesani karti:\n";
    for (int i = 0; i < 54; i++) {
        cout << deck[i] << ", ";
    }
    cout << "\n\n";

    // Mesanje na kartite so ,,Fisher-Yates" algoritmot
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g); /*random_device se koristi za generator na slucaen broj Mersenne Twister (mt19937), se generira
                                            psevdo-slucajni broevi. Potoa f-jata shuffle() gi mesa elementite so koristenje na generiranite slucajni broevi*/

    //Se prikazuva spilot posle mesanje na kartite
    cout << "Kartite posle mesanje:\n";
    for (int i = 0; i < 54; i++) {
        cout << deck[i] << ", ";
    }
    cout << "\n\n";

    //Delenje na kartite na 4 igraci
    array<array<string, 13>, 4> players; //se pravat 4 nizi za igracite
    int card_index = 0;
    for (int i = 0; i < 4; i++) { //se delat po 13 karti na sekoj igrac
        for (int j = 0; j < 13; j++) {
            players[i][j] = deck[card_index]; //se dodava odredenata karta na togasniot igrac
            card_index++;
        }
    }

    //Prikazuvanje kako kartite izlgedaat kaj sekoj od 4te igraci
    for (int i = 0; i < 4; i++) {
        cout << "Karti na igrac " << i+1 << ":\n";
        for (int j = 0; j < 13; j++) {
            cout << players[i][j] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
