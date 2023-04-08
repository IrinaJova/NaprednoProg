//NP-lab.06 INKI1053 Irina Jovanoska
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition
struct card {
   const char *face; // define pointer face
   const char *suit; // define pointer suit
}; // end struct card

typedef struct card Card; // new type name for struct card

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );

int main( void )
{
   Card deck[ CARDS ]; // define array of Cards

   // sto se pravi vo ovoj red - se kreira niza od pokazuvaci kon konstantni stringovi, koi gi opisuvaat ,,licata"/broevi na kartite vo spilot
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   // sto se pravi vo ovoj red - se kreira niza od pokazuvaci kon konstantni stringovi koi opisuvaat znaci na kartite vo eden spil
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   srand( time( NULL ) ); /* sto e ovaa naredba - se generira nov slucaen broj i sekoj pat koga ke se startuva programata, ke se 
                            generira razlicen spil so slucajno raspredeleni karti*/

   fillDeck( deck, face, suit ); 
   shuffle( deck ); 
   deal( deck ); 
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] )
{
   size_t i; 

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   } // end for
} // end function fillDeck

// shuffle cards
void shuffle( Card * const wDeck )
{
   size_t i; // sto e ovaa promenliva - se koristi kako brojac vo naredbite za povtoruvanje
   size_t j; // sto e ovaa promenliva i vo koi vrednosti se dvizi - se cuva slucajna vrednost megu vrednostite od 0-51  
   Card temp; // define temporary structure for swapping Cards

   // loop thr
   for ( i = 0; i < CARDS; ++i ) {
      j = rand() % CARDS; // 
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   } // end for
} // end function shuffle

// deal cards
void deal( const Card * const wDeck )
{
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s of %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4 ? "  " : "\n" );
   } // end for
} // end function deal

/*Ova e programa za igranje na karti. Vo ovaa programa ,,face" i ,,suit" promenlivite se nizi so zborovi za licata
i broevite na kartite. ,,shuffle" funkcijata gi menuva poziciite na kartite vo spilot na slucaen nacin.*/