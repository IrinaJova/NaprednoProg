#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int DECK_SIZE = 54; //Ima 52 karti vo spil, so dodavanje na 2 jokeri stanuvaat 54
const int SUIT_SIZE = 13;
const int NUM_SUITS = 4;

string suits[NUM_SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
string ranks[SUIT_SIZE] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
string jokers[2] = {"Joker #1", "Joker #2"}; //Niza za da se stavat dvata jokeri

void shuffleDeck(string deck[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        string temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    string deck[DECK_SIZE];
    int index = 0;
    
    //Se stavaat karti vo spilot
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < SUIT_SIZE; j++) {
            deck[index] = ranks[j] + " of " + suits[i];
            index++;
        }
    }
    
    //Se dodavaat uste 2ta jokeri vo spilot
    for (int i = 0; i < 2; i++) {
        deck[index] = jokers[i];
        index++;
    }
    
    //Ispisuvanje na spilot po redosled na kartite
    cout << "Deck in order:" << endl;
    for (int i = 0; i < DECK_SIZE; i++) {
        cout << deck[i] << endl;
    }
    cout << endl;
    
    srand(time(NULL)); //Generiranje na nekoj random broj
    shuffleDeck(deck, DECK_SIZE); //Mesanje na kartite
    
    //Se ispisuva redosledot na kartite posle mesanjeto zaedno so jokerite
    cout << "Deck after shuffling:" << endl;
    for (int i = 0; i < DECK_SIZE; i++) {
        cout << deck[i] << endl;
    }
    
    return 0;
}

/*Posle prebaruvanje na internet, ovaj algoritam e poznat kako mesanje na Fisher-Yates
ili Knuth shuffle i e siroko koristen za algoritam za slucajno mesanje na nizi.*/
