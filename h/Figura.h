#ifndef FIGURA_H
#define FIGURA_H

#include <fstream>
#include <iostream>

using namespace std;

typedef enum //Facilita l'aplicacio del colors a les figures
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum //Facilita l'aplicacio del tipus o forma de les figures per tractarlos diferent
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;

const int MAX_VERTICAL = 4; //El tamany maxim vertical de la matriu de la figura
const int MAX_HORITZONTAL = 4; //El tamany maxim horitzontal de la matriu de la figura

typedef enum //Facilita saber si parlem d'un gir horari (->) o antihorari (<-)
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    //constructors
    Figura();
    
    //getters
    int getX() { return m_x; }
    int getY() { return m_y; }
    int getVertical() { return m_alcada; }
    int getHoritzontal() { return m_amplada; }
    ColorFigura getColor(int i, int j) const { return m_figura[i][j]; }
    
    //setters
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    
    
    void crearFigura(TipusFigura figura, int x, int y); //funcio per generar una nova figura
    void getMatrix(ColorFigura matrix[MAX_VERTICAL][MAX_HORITZONTAL]) const; //funcio per recuperar la matriu d'una figura (MATRIX li diguem a les matrius de les figures copiades)

    void gir(DireccioGir gir); //Funcio que aplica el gir a la figura
    void mouHoritzontal(int dirX) { m_x += dirX; }; //Funcio que aplica el moviment ja sigui a la dreta o a l'esquerra a la figura
    void baixaFila() { m_y++; } //Funcio que baixa el grup d'una fila en una posicio, com que l'eix y va de (- -> +) pues es "m_y++"" i no "m_y--""

private:
    int m_x; //Posicio de la figura en l'eix x
    int m_y; //Posicio de la figura en l'eix y
    int m_alcada; //alçada de la matriu de la figura 2 -> 4
    int m_amplada; //amplada de la matriu de la figura 2 -> 4

    TipusFigura m_tipus; //tipus de la figura (enum TipusFigura)
    ColorFigura m_color; //color de la figura (enum ColorFigura)
    ColorFigura m_figura[MAX_VERTICAL][MAX_HORITZONTAL]; //matriu de la figura (objecte)
    
    void transposada(); // funcio privada que es crida des de gira figura per trasposarla
    void invertir(ColorFigura marix[][MAX_HORITZONTAL], bool filCol); // funcio privada que es crida des de gira figura i que decideix si es gir horari o antihorari depenen del bool filCol
    void initFiguraDrecera(int vertical, int horitzontal, ColorFigura matrix[][MAX_HORITZONTAL], int color); //aglomera varis cases per fer el codi mes simple
    void initFiguraDrecera2For(int vertical, int horitzontal, ColorFigura matrix[][MAX_HORITZONTAL], int color); //aglomera 2 casos per fer el codi mes simple
    // actualment encara estem miran d'aglomerar mes coses
};

#endif