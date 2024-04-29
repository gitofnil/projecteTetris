#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public: 
    Tauler(ColorFigura m_tauler[MAX_FILES][MAX_COL]);
    bool setm_tauler(const int x, const int y, const int color, const int tipusFigura);
    void setm_taulerInicialitzacio(const int tipus, const int fila, const int columna, const int gir);
    void setm_figuraActual(const int x, const int y, const int tipus, const int gir);
    int getm_tauler(const int fila, const int columna);
    bool girValid(DireccioGir direccio);
    bool movValid(int dirX);
    void colocaFigura();
    void eliminarFila();

private:
    ColorFigura m_tauler[MAX_FILES][MAX_COL];
    Figura m_figuraActual;

    bool filaEliminable();
    bool colisioLimits();
    bool colisioAltresFigures();
};
#endif