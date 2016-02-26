// Definitie van klasse Stand.

const int NMAX = 50;  // of iets anders
const int groot = 25; // of iets anders
const int vaak = 30;  // of iets anders
const int GeenKolom = -1;

class Stand
{ public:
    // constructors
    Stand ();  // misschien niet nodig voor deze opdracht...
    Stand (int waardeN);

    // eventueel destructor ~Stand ()
    //~Stand ();
    
    
    
    //Aantal kollomen n(private) member functies
    int getN (){
      return n;
    }
    

    // Drukt bord af op het scherm.
    void drukaf ();

    // Bepaalt een winnende zet voor de speler die aan de beurt is.
    // Telt in de parameter `aantal' ook het aantal (tussen)standen
    // dat bekeken wordt.
    // Retourneer: - kolom van de winnende zet als er een winnende zet is
    //             - GeenKolom als alle zetten (>=1) verlies opleveren
    int winst (int &aantal);

    // Doet een zet voor pion in kolom `kolom'.
    // Handig om verschillende versies te maken voor een slagzet
    // en een gewone zet
    void doezet (int kolom);

    // Bepaalt een `beste' zet door voor alle mogelijke directe vervolgstanden
    // `vaak' random vervolgspelen te spelen.
    int bestezet ();

    // Bepaalt een random toegestane zet en voert die uit.
    void doerandomzet ();

    // Controleert of de stand een eindstand is of niet.
    bool eindstand ();
    
    

    char bord[3][NMAX];
    char aanDeBeurt;
    

  private:
    int n;  // feitelijke aantal kolommen van het bord   
     //Maximale grootte bord
  
    char wit = 'W', zwart = 'Z', leeg = ' ';
  

      // En verder onder andere een bord in de vorm van een
      // tweedimensionaal char-array.
};

