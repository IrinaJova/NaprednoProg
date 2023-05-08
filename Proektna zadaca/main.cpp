#include <iostream>  
#include <string>    
#include <vector>    
#include <algorithm> 
#include <random>

using namespace std;

//Proverka dali kartata e validna
bool ValidnaKarta(const string& karta) {
    //definiranje na validni znaci i broevi
    vector<string> simboli = { "Lokum", "Srce", "List", "Detelina" };
    vector<string> broevi = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Dzandar", "Kralica", "Kral" };

    //inicijalizacija na znaci i broevi na prazni stringovi
    string simbol, broj;

    //Se bara znakot i brojot vo stringot
    for (const string& s : simboli) {
        if (karta.find(s) != string::npos) {
            simbol = s;
            break;
        }
    }
    for (const string& b : broevi) {
        if (karta.find(b) != string::npos) {
            broj = b;
            break;
        }
    }

    //Proverka dali znakot so brojot se validni
    return !simbol.empty() && !broj.empty();
}

int main() {
    srand(time(NULL)); //sluzi za generiranje na random broevi

    //Definiranje na spilot
    vector<string> simboli = { "Lokum", "Srce", "List", "Detelina" };
    vector<string> broevi = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Dzandar", "Kralica", "Kral" };
    vector<string> spil;
    for (const string& simbol : simboli) {
        for (const string& broj : broevi) {
            spil.push_back(simbol + ", " + broj); //se dodava kartata vo spilot
        }
    }
    random_device rd;  //se kreira random device 
    mt19937 g(rd());  // kreiranje na Mersenne Twister random generator na broevi
    shuffle(spil.begin(), spil.end(), g);  //se mesa spilot so pomos na ovoj generator

    //se izvlekuvaat 5 karti
    vector<string> raka;
    while (raka.size() < 5) {
        int index = rand() % spil.size();  //Se generira random kombinacija 
        string karta = spil[index];         //Se zema taa karta
        if (find(raka.begin(), raka.end(), karta) == raka.end() && ValidnaKarta(karta)) {  //Tuka se vrsi proverka dali kartata e validna i veke vo tie 5 karti
            raka.push_back(karta);         //Se dodava kartata vo ,,rakata"
            spil.erase(spil.begin() + index);  //Se odzema kartata od spilot
        }
    }
    cout << "Vasite podeleni karti se: \n";
    //Printanje na kartite
    for (const string& karta : raka) {
        cout << karta << endl;
    }
    return 0;
}
