#include "Tauler.h"

bool Tauler::setm_tauler(const int x, const int y, const int color, const int tipusFigura);
{
    bool figuraColocada = false;

    if ((x <= 7 && x >= 0) && (y <= 7 && y >= 0))
    {
        m_tauler[x][y].setColor(color);
        m_tauler[x][y].setTipus(tipusFigura);
        figuraColocada = true;
    }   

    return figuraColocada;
}

void setm_taulerInicialitzacio(const int x, const int y, const int color)
{
        bool seccioColocada = false;

    if ((x <= 7 && x >= 0) && (y <= 7 && y >= 0))
    {
        m_tauler[x][y].setColor(color);
        seccioColocada = true;
    }   

    return seccioColocada;
}

void Tauler::setm_figuraActual(const int tipus, const int fila, const int columna, const int gir)
{
    m_figuraActual.setX(columna);
    m_figuraActual.setY(fila);
    m_figuraActual.setTipus(tipus);
    m_figuraActual.setGir(gir);
}