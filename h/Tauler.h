#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    //Constructor de la clase
    Tauler();
    
    //seters
    void setColor(int i, int j, ColorFigura color) { m_tauler[i][j] = color; }
    
    //getters
    ColorFigura getCasella(int i, int j) const { return m_tauler[i][j]; }
    
    void getTauler(ColorFigura matriu[MAX_FILA][MAX_COL], Figura& figura); /*funcio que et "retorna" en la matriu "matrix" que es pasa per 
referencia la matriu del tauler i tambe "retorna" el el parametre figura "figura" que es pasa per referencia les "stats" de la figura*/
    bool xoca(Figura& figura) const; /*funcio que comproba que la figura pasada per referencia no colisioni amb altres objectes del joc, fa servir la funico comprovaXoc (esta a tauler.h) per fer-ho, retorna un bool,
0 no xoca, 1 xoca*/
    int eliminaFila(); //elimina les files senceres del tauler i retorna el nombre de files que ha eliminat

private:
    
    bool comprovaXoc(int i, int j, int x, int y, Figura& figura) const { return (figura.getColor(i, j) != COLOR_NEGRE) && 
((j + x < 0 || j + x > MAX_COL - 1 || i + y > MAX_FILA - 1) || m_tauler[i + y][j + x] != COLOR_NEGRE); } // funcio que fa les comprovacions de la funcio xoc

    ColorFigura m_tauler[MAX_FILA][MAX_COL]; //variable que emmagatzema el tauler amb el que treballaem
};
