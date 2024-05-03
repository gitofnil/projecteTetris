#include "Tauler.h"
#include "Figura.h"

class Joc
{
public:
    //Constructor
	Joc() {};
	
	void inicialitza(const string& nomFitxer); //inicialitzador de totes les variables del joc, les posa al seu estat "dafault"
	bool giraFigura(DireccioGir direccio); //funcio que gira la figura, per tal de fer-ho demana informacio de si es xoca la figura amb parts de la grid del joc o amb altres figures
	int baixaFigura(); //Funcio que fa que baixi la figura en questio una casella cada vegada sempre i cuant no es xoqui contra elguna cosa (bordes o altres peces)
	bool mouFigura(int dirX); //funcio que mou la figura cap a la dreta o esquerra depenent del que se li indiqui a dirX
	
	void escriuTauler(const string& nomFitxer); //Funcio que escriu el tauler en el fitxer de sortida

private:
	Tauler m_tauler; //variable on es guarda el tauler actual del joc
	Figura m_figura; //variable on es guarda la figura que actualment esta en accio (la que cau) en el joc
};

