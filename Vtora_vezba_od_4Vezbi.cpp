#include <iostream>
#include <cstring>

using namespace std;

int main() {
    //deklaracija i inicijalizacija na ime od pesna i izveduvacot
    const char pesna[] = "I was never there";
    const char izveduvac[] = "The Weeknd";

    //Se ispisuva imeto i izeduvacot na pesnata
    cout << "Pesna: " << pesna << endl;
    cout << "Izveduvac: " << izveduvac << endl;

    //Inicijalizacija na prviot karakter, negovata adresa, i originalniot cel string so pokazuvac
    const char *p = pesna;
    cout << "Prv karakter: " << *p << endl;
    cout << "Adresa na prviot karakter: " << static_cast<const void *>(p) << endl;
    cout << "Originalna niza: " << pesna << endl;

    //Se broi kolku karakteri ima vo pesnata i vo imeto na izveduvacot
    int dolzina_pesna = strlen(pesna);
    int dolzina_izveduvac = strlen(izveduvac);

    //Se broi kolku mesta treba da se pomestat za da se isprinta samo imeto na izveduvacot
    int pomesti_kursor = dolzina_pesna - dolzina_izveduvac;

    //Se pomestuva kursorot na pocetnata pozicija od imeto na izveduvacot
    p += pomesti_kursor;

    //Se prikazuvva prviot karakter, adresata i pozicijata od nizata posle pomestuvanjeto 
    cout << "Prv karakter posle pomestuvanjeto: " << *p << endl;
    cout << "Adresa na prviot karakter posle pomestuvanjeto: " << static_cast<const void *>(p) << endl;
    cout << "Nizata posle pomestuvanjeto: " << p << endl;

    return 0;
}
