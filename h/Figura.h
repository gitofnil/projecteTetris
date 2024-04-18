#ifndef FIGURA_H
#define FIGURA_H

typedef enum
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


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    int getX() {return m_x;}
    int getY() {return m_y;}
    char getTipus() {return m_tipus;}
    char getColor() {return m_color;}
    char getGir() {return m_gir;}

    int setX(x) {}
    int setY()  {}
    char setTipus() {}
    char setColor() {}
    char setGir() {}


private:
    int m_x;
    int m_y;
    char m_tipus;
    char m_color;
    char m_gir;

};


#endif
