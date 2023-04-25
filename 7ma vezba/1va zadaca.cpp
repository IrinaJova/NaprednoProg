#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Date {
private:
    int day, month, year, hour, minute, second;
public:
    Date(){}
    
    friend istream& operator>>(istream& in, Date& d); //Overloading >> operator
    friend ostream& operator<<(ostream& out, const Date& d); //Overloading << operator

    ~Date(){}
};

istream& operator>>(istream& in, Date& d) {
    // Pokazuvanje kako korisnikot da vnesi den, mesec, godina, i cas vo format od "dd/mm/yyyy hh:mm:ss"
    cout << "Enter date in format (dd/mm/yyyy hh:mm:ss): ";
    char slash, colon;
    //Se ,,citaat" vnesenite podatoci
    in >> d.day >> slash >> d.month >> slash >> d.year >> d.hour >> colon >> d.minute >> colon >> d.second;
    // proverka dali mesecite se megju 1 i 12
    if (d.month < 1 || d.month > 12) {
        cout << "Invalid month\n";
        exit(0);
    }
    return in;
}

ostream& operator<<(ostream& out, const Date& d) {
    out << "Date: " << d.day << "/" << d.month << "/" << d.year << " ";
    out << "Time: " << d.hour << ":" << d.minute << ":" << d.second << endl;
    return out; 
}

int main() {
    Date d;
    cout << "Enter a date and time:\n";
    //,,citanje" na podatocite so koristenje na overloaded >> operator
    cin >> d;
    cout << "You entered:\n" << d;
    return 0;
}
