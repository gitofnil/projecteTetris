#include "Joc.h"
#include <iostream>
#include <fstream>

using namespace std;

// inicialitza la matriu del tauler amb un "preset" i afageix una figura caiguen
void joc::inicialitza(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);

    int color;
    int tipus, fila, columna, gir;
 
    // com que totes les inicialitzacions son iguals, no faig eof
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fitxer >> tipus >> fila >> columna >> gir;
            Tauler::setm_figuraActual(tipus, fila, columna, gir);
        }
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            fitxer >> color;
            Tauler::setm_taulerInicialitzacio(i, j, color);
        }
    }

    fitxer.close();
}

// escriu la matriu del tauler, nomes el color de cada seccio a un fitxer
void escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    int color; 

    for(int i = 0; i < MAX_ALCADA; i++)
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            color = Tauler::getColor(i, j);
            fitxer << color;
        }

    fitxer.close();
}

// exercici 5, pensar com implementarem la core del joc;
/* Per poder implementar el metode gira figura, jo faria un switch case dins del metode per actuar diferent en cada cas, 
despres faria un altre switch case dins del metode colisioLimits i colisio altres figures i calcularia el gir, miraria en aquest cas
si colsiona contra les parets i/o contra una altre figura, en cas positiu d'algun dels dos o dels dos, no s'executaria el gir, aixo es faria amb un
const de la variable, ja que no la volem cambiar, volem fer un "snapshot" de la figura a moure, no volem cambiar l'original. mou figura es faria igual,
es calcula el moviment, es mira si colisiona i en cas afirmatiu dons no s'efectua el moviment. en el cas que el jugador estigui satisfet amb la posicio de la figura
pot baixarla i aixis tencar l'actiu i tornarlo en un conjunt mes de peces del tauler, en aquest cas, s'ha de caluclar en quin moment te la primera colisio contra una
altre pessa, moven la pessa de manera continuada amb un while*/


