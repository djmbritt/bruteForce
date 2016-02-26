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

auto line = [](auto len){
  cout << endl;
  for(auto p=0; p<=len; p++){
    cout << "┼───";
  }
  cout << "┼" << endl;
};



// Drukt bord af op het scherm.
void Stand::drukaf (){ 

  cout << endl << "Aan de beurt: " 
       << ((aanDeBeurt == wit) ? "Wit" : "Zwart") 
       << endl;

  line(n);
  
  for(auto k=0; k<=n; k++){  
    if(k<10){
      cout << "│ " << k << " ";
    }else{
      cout << "│" << k << " ";
    }
  }
  
  cout << "│";  
  line(n);
  
  for(auto i=0; i<3; i++){
    for(auto j=0; j<=n; j++){
        cout << "│ " << bord[i][j] << " ";
    }
    cout << "│";
    line(n);
  }
  
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
void Stand::doezet (int kolom){

  if(bord[1][kolom] == leeg){
    
    if(aanDeBeurt == wit){
      if(bord[2][kolom] == leeg){
        cout << "Zet niet mogelijk." << endl;
      } else {
        bord[1][kolom] = aanDeBeurt;
        bord[2][kolom] = leeg;
        aanDeBeurt = zwart;
      }
    }else{
      if(bord[0][kolom] == leeg){
        cout << "Zet is niet mogelijk." << endl;
      } else {
        bord[1][kolom] = aanDeBeurt;
        bord[0][kolom] = leeg;
        aanDeBeurt = wit;
      }
    }
  } else {
    cout << "Veld is niet leeg." << endl;
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

