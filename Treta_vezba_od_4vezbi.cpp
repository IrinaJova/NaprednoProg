#include <iostream>
#include <cmath>
using namespace std;

void sobiranje(int x, int y) {
    cout << "Sumata na " << x << " i " << y << " e " << x+y << endl;
}

void odzemanje(int x, int y) {
    cout << "Razlikata na " << x << " i " << y << " e " << x-y << endl;
}

void delenje(float x, float y) {
    cout << "Kolicnikot od " << x << " i " << y << " e " << x/y << endl;
}

void stepenuvanje(double x, double y) {
    cout << x << " stepenuvano na brojot " << y << " e " << pow(x, y) << endl;
}

void presmetaj(int x, int y, void (*operacija)(int, int)) {
    operacija(x, y);
}

void presmetaj(float x, float y, void (*operacija)(float, float)) {
    operacija(x, y);
}

void presmetaj(double x, double y, void (*operacija)(double, double)) {
    operacija(x, y);
}

int main() {
    char ime = 'I';
    char prezime = 'J';
    int x = int(ime);
    int y = int(prezime);
    void (*operacija1)(int, int);
    void (*operacija2)(float, float);
    void (*operacija3)(double, double);

    operacija1 = &sobiranje;
    presmetaj(x, y, operacija1);

    operacija1 = &odzemanje;
    presmetaj(x, y, operacija1);

    operacija2 = &delenje;
    presmetaj(x, y, operacija2);

    operacija3 = &stepenuvanje;
    presmetaj(x, y, operacija3);

    return 0;
}
