
#include <iostream>
#include "stand.h"
using namespace std;

//*************************************************************************

bool integerInBereik (const char *variabele, int waarde,
                      int minWaarde, int maxWaarde)
{
  if (waarde>=minWaarde && waarde<=maxWaarde)
    return true;
  else
  { cout << variabele << "=" << waarde << ", maar moet in [" << minWaarde
         << "," << maxWaarde << "] liggen." << endl;
    return false;
  }

}  // integerInBereik

//*************************************************************************

// Speelt het spel vanaf stand s1.
// Hierbij krijgt de gebruiker herhaaldelijk de keuze om een zet (kolom)
// in te voeren. Als dat een toegestane zet is, wordt die uitgevoerd,
// waarna het programma een randomzet doet.
// Na iedere zet wordt de stand afgedrukt.
// Als de gebruiker aan de beurt is, doet het programma eerst nog
// * als n<=groot, een suggestie voor een winnende zet (als die bestaat),
// * als n>groot, een suggestie voor een best lijkende zet
//
// Dit alles gaat door
// * totdat er een eindstand is bereikt
// * of totdat de gebruiker aangeeft dat hij wil stoppen met het spel
void doeSpel (Stand *s1)
{ int n,
      keuze=0,
      kolom,
      aantal;  // aantal bekeken standen bij aanroep van winst
  // TODO: andere variabelen die u nodig hebt...

  n = s1->getN ();

  while (keuze!=2)  // of een andere stopconditie en/of een do-lus
  {
    // TODO: doe een suggestie voor een winnende of best-lijkende zet...

    cout << endl;
    cout << "1. Een zet doen" << endl;
    cout << "2. Stoppen met dit spel" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    switch (keuze)
    { case 1: cout << "Geef het nummer van een kolom: ";
              cin >> kolom;
              cout << endl;
                // TODO: Voer zo mogelijk de zet uit en vervolgens
                // een randomzet door het programma.
                // Druk de resulterende standen ook af.
                 if(kolom < 0 || kolom > n){
                   cout << "Zet is niet mogelijk, probeer opnieuw." << endl;
                   break;
                 }else{                
                   s1->doezet(kolom);
                   s1->drukaf();
                 }
              break;
      case 2: break;
      default: cout << "Voer een goede keuze in!" << endl;
    }  // switch

  }  // while

}  // doeSpel

//*************************************************************************

// Voert de experimenten uit zoals beschreven op blz 4 van de opdracht.
void doeExperimenten ()
{
   // TODO: alle code om de beschreven experimenten uit te voeren

}  // doeExperimenten

//*************************************************************************

void hoofdMenu ()
{ Stand *s1;  // Pointer is handig voor het opzetten van een nieuw spel
              // en het weggooien van het oude.
  int keuze,
      n;

  do
  {
    cout << endl;
    cout << "1. Een spel spelen" << endl;
    cout << "2. Experimenten doen" << endl;
    cout << "3. Stoppen" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    switch (keuze)
    { case 1: cout << "Geef een waarde voor de bordgrootte n: ";
              cin >> n;
              
              if (integerInBereik ("n", n, 1, NMAX)) { 
                s1 = new Stand (n);
                s1 -> drukaf ();

                doeSpel (s1);

                delete s1;  // netjes opruimen
              }
              break;
      case 2: doeExperimenten ();
                break;
      case 3: break;
      default: cout << "Voer een goede keuze in!" << endl;
    }

  } while (keuze!=3);
  
}  // hoofdMenu

//*************************************************************************

int main ()
{
  hoofdMenu ();
  
  return 0;

}
