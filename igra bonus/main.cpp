#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>


using namespace std;

const int Sirina = 30; //sirina na pole za delot od igrata
const int visina = 20; //visina na pole za delot od igrata
const int golemina = Sirina * visina; //vk. golemina na pole za igranje

enum Direkcii { UP, DOWN, LEFT, RIGHT }; //promenliva za direkcii

struct Snake {
    vector<int> body;  //dinamicka niza za opisuvanje na teloto od zmijata 
    Direkcii dir; //promenliva za def. na pravecot od zmijata 
    bool dead; //promenliva za sostojba na zmijata 
};

void draw(Snake snake, int food) { //f-ja za crtanje na igrata 
    system("cls"); //se brise prethodniot izgled na prozorecot
    for (int i = -1; i <= visina; i++) { //ciklus za opis na sekoj red od poleto za igranje
        for (int j = -1; j <= Sirina; j++) { //ova e za kolona 
            if (i == -1 || i == visina || j == -1 || j == Sirina) { //proverka dali sme vo granicata na poleto za igranje 
                
                cout << "#";
            }
            else {
                int pos = i * Sirina + j; //se presmetuva pozicijata na momentalnata kelija
                if (snake.dead && snake.body[0] != pos) { //zapis na teloto od mrtvata zmija
                    cout << "X";
                }
                else if (snake.body[0] == pos) { //glava na zmijata
                    cout << "O";
                }
                else if (food == pos) { //ako pozicijata e na hranata da se prikaze *
                    cout << "*";
                }
                else {
                    bool tail = false;
                    for (int k = 1; k < snake.body.size(); k++) {
                        if (snake.body[k] == pos) {
                            //ako pozicijata e ,,okupirana" od teloto na zmijata se ispisuva o
                            tail = true;
                            break;
                        }
                    }
                    cout << (tail ? "o" : " "); //se pravi izbor pomegu crtanje na o ili prazno mesto
                }
            }
        }
        cout << endl;
    }
    cout << "Score: " << snake.body.size() - 1 << endl; //se pokazuva skorot na igracot
}

int main() {
    srand(time(NULL)); //se generira random broj so segasnoto vreme
    Snake snake = { {golemina / 2}, RIGHT, false };//inicijalizacija na pozicijata od zmijata, direkcii
    int food = rand() % golemina;//random pozicija na hranata

    while (!snake.dead) {
        draw(snake, food);//se prikazuva celosnoto pole za igra
        if (_kbhit()) { //proverka dali se pritisnalo kopce
            char c = _getch();//koe kopce e pritisnato
            switch (c) {
            case 'w': snake.dir = UP; break;
            case 's': snake.dir = DOWN; break;
            case 'a': snake.dir = LEFT; break;
            case 'd': snake.dir = RIGHT; break;
            }
        }
        int head = snake.body[0];//glavata da bide prv element od zmijata 
        switch (snake.dir) {
        case UP: head -= Sirina; break;
        case DOWN: head += Sirina; break;
        case LEFT: head--; break;
        case RIGHT: head++; break;
        }
        //ako glavata e nadvor od granicite se gubi 
        if (head < 0 || head >= golemina) {
            snake.dead = true;
        }
        //proverka dali glavata e kaj hranata
        else if (snake.body[0] == food) {
            snake.body.insert(snake.body.begin(), head); //se dodava nov del na teloto
            food = rand() % golemina;
        }
        else {
            snake.body.pop_back();
            if (find(snake.body.begin(), snake.body.end(), head) != snake.body.end()) { //dali glavata se sudrila so teloto
                snake.dead = true;
            }
            snake.body.insert(snake.body.begin(), head);
        }
        Sleep(200); 
    }
    draw(snake, food);
    cout << "Game over! Score: " << snake.body.size() - 1 << endl;
    return 0;
}
