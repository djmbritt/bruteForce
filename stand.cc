// Implementatie van klasse Stand.

#include <iostream>
#include "stand.h"
using namespace std;

// constructors
Stand::Stand (){
  // TODO
}

Stand::Stand (int waardeN){ 
  aanDeBeurt = wit;
  n = waardeN;
  bord[3][n];
  
  for(auto i=0; i<=n; i++){
    bord[0][i] = zwart;
    bord[1][i] = leeg;
    bord[2][i] = wit;
  }

}

// Drukt bord af op het scherm.
void Stand::drukaf (){ 

  //line 0
  cout << endl << endl;
  for(auto p=0; p<=n; p++){
    cout << "┼───";
  }
  cout << "┼" << endl;
    
  //numbers row top
  for(auto p=0; p<=n; p++){  
    if(p<10){
      cout << "│ " << p << " ";
    }else{
      cout << "│" << p << " ";
    }
  }
  
  //line1
  cout << "│";  
  cout << endl;
  for(auto p=0; p<=n; p++){
    cout << "┼───";
  }
  cout << "┼" << endl;
  
  //black, empty, white rows and line 2,3,4
  for(auto i=0; i<3; i++){
    for(auto j=0; j<=n; j++){
        cout << "│ " << bord[i][j] << " ";
    }
    cout << "│";
    cout << endl;
    for(auto p=0; p<=n; p++){
      cout << "┼───";
    }
    cout << "┼" << endl;
  }
  
  //number row bottom
  for(auto p=0; p<=n; p++){
    if(p<10){
      cout << "│ " << p << " ";
    }else{
      cout << "│" << p << " ";
    }
  }
  cout << "│" << endl;
  
  //line 5 (last line)
  for(int p=0; p<=n; p++){
    cout << "┼───";
  }
  cout << "┼";  
  
  //player indicator
  cout << endl << "Aan de beurt: "
       << ((aanDeBeurt == wit) ? "Wit" : "Zwart");
  
}

// Bepaalt een winnende zet voor de speler die aan de beurt is.
// Telt in de parameter `aantal' ook het aantal (tussen)standen
// dat bekeken wordt.
// Retourneer: - kolom van de winnende zet als er een winnende zet is
//             - GeenKolom als alle zetten (>=1) verlies opleveren
int Stand::winst (int &aantal)
{ // TODO: echte implementatie
  // Houd hierbij ook rekening met het geval dat de stand een eindstand is
  // (of wordt). Zo'n stand is winnend voor de speler die dan aan de beurt is.
  // Een mogelijkheid is om `winst' in dit geval een speciale waarde
  //  te laten retourneren.

  return 1;
}

// Doet een zet voor pion in kolom `kolom'.
// Handig om verschillende versies te maken voor een slagzet
// en een gewone zet

//Sigui traha riba doezet, mi a purba implementa e for loop na cuminsamento 
//pero e no ta trahando manera mi ker, mi tin cu incorpora e if statement mas abouw
// cu e if(bord[1][kolom] == leeg), hunto cu e for loop.
// tin parti nan di e logica cu ta overlap cu otro anto nan mester wordo incorpora mas miho cu otro.
// ademas tin parti nan overbodig y cu ta pafo di e scope di e regla nan cu no ta cuadra.
bool Stand::moetslaan (int kolom){
  if(aanDeBeurt == wit){
    if(bord[2][kolom-1] != leeg && bord[2][kolom+1] != leeg){
      cout << aanDeBeurt <<  " moet slaan!" << bell;
      return false;
    } else {
      return true;
    }
  }else{
    if(bord[0][kolom-1] != leeg && bord[0][kolom+1] != leeg){
      cout << aanDeBeurt << "moet slaan!" << bell;
      return false;
    } else {
      return true;
    }
  }
}

void Stand::doezet (int kolom){
  int i;
  for(i=0; i<=n; i++){
    if(bord[1][i] != leeg){
      cout << "Je moet slaan!" << endl
           << aanDeBeurt << " heeft een steen die op rij: " << i 
           << " geslagen moet worden." << endl; 
      return;
    }  
  }
    if(bord[1][i] != leeg){
      if(aanDeBeurt == wit){
        if(bord[2][i-1] == zwart || bord[2][kolom+1] == zwart){
          cout << bell << "Slaan is verplicht!" << kolom << endl;
          return;
        }else{
          bord[2][kolom] = leeg;
          bord[1][((kolom-1 == zwart) ? kolom-1 : kolom+1)] = aanDeBeurt;
          aanDeBeurt = zwart;
          return;
        }
      }else{//aanDeBeurt == zwart
        if(bord[0][i-1] == wit || bord[0][i+1] == wit){
          cout << bell << "Slaan is verplicht!" << endl;
          return;
        }else{
          bord[0][kolom] = leeg;
          bord[1][((kolom-1 == wit) ? kolom-1 : kolom+1)] = aanDeBeurt;
          aanDeBeurt = wit;
          return;
        }
      }  
    }else if(bord[1][kolom] == leeg){
    
    if(aanDeBeurt == wit){
      if(bord[2][kolom] == leeg){
        cout << bell << "Zet niet mogelijk." << endl;
        return;
      } else {
        bord[1][kolom] = aanDeBeurt;
        bord[2][kolom] = leeg;
        aanDeBeurt = zwart;
      }
    }else{//aanDeBeurt == zwart
      if(bord[0][kolom] == leeg){
        cout << bell << "Zet is niet mogelijk." << endl;
        return;
      } else {
        bord[1][kolom] = aanDeBeurt;
        bord[0][kolom] = leeg;
        aanDeBeurt = wit;
      }
    }
  } else {
    cout << bell << "Veld is niet leeg." << endl;
    return;
  }
  
}

// Bepaalt een `beste' zet door voor alle mogelijke directe vervolgstanden
// `vaak' random vervolgspelen te spelen.
int Stand::bestezet (){
  // TODO: echte implementatie
  return 1;
}

// Bepaalt een random toegestane zet en voert die uit.
void Stand::doerandomzet (){ 
  // TODO
}

// Controleert of de stand een eindstand is of niet.
bool Stand::eindstand (){ 
  // TODO: echte implementatie
  return false;
}

