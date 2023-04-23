#include <iostream>
#include <cmath>
using namespace std;

class operations {
public:
    int num1, num2;
    void input() { //vnes na broj od korisnik
        cout << "Enter two numbers to perform operations on: \n";
        cin >> num1 >> num2;
        cout << "\n";
    }
    void addition() {
        cout << "Addition = " << num1 + num2; //sobiranje na dvata broja
        cout << "\n";
    }
    void subtraction() {
        cout << "Subtraction = " << num1 - num2; //odzemanje na dvata broja
        cout << "\n";
    }
    void multiplication() {
        cout << "Multiplication = " << num1 * num2; //mnozenje na dvata broja 
        cout << "\n";
    }
    void division() {
        cout << "Division = " << (float) num1 / num2; //delenje na dvata broja
        cout << "\n";
    }
    void power() {
        cout << "Power = " << pow(num1, num2); //stepenuvanje na dvata broja
        cout << "\n";
    }
    void exponentiation() {
        double euler = exp(1.0);
        cout << "Exponentiation = " << euler * exp(num1+num2); // e na stepen od zbirot na dvata broja
        cout << "\n";
    }
};

int main() {
    cout << " ===== Program to perform basic operations using Class, in CPP ===== \n\n";
    operations op;
    int choice;
    cout << "Enter your choice:\n";
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
    cout << "5. Power\n6. Exponentiation\n";
    cin >> choice;
    switch (choice) {
        case 1:
            op.input();
            op.addition();
            break;
        case 2:
            op.input();
            op.subtraction();
            break;
        case 3:
            op.input();
            op.multiplication();
            break;
        case 4:
            op.input();
            op.division();
            break;
        case 5:
            op.input();
            op.power();
            break;
        case 6:
            op.input();
            op.exponentiation();
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }
    cout << "Exiting the program\n";
    return 0;
}
