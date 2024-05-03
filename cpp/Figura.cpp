#include "Figura.h"

//Funcions essencials per al funcionament de la classe (constructors, getters i setters)
Figura::Figura()
{
    initFiguraDrecera2For(MAX_VERTICAL, MAX_HORITZONTAL, m_figura, m_color);
    
    m_color = NO_COLOR;
    m_tipus = NO_FIGURA;
    m_alcada = 0;
    m_amplada = 0;
    m_x = 0;
    m_y = 0;
    
}

void Figura::getMatrix(ColorFigura matrix[MAX_VERTICAL][MAX_HORITZONTAL]) const
{
    for (int i = 0; i < m_alcada; i++)
        for (int j = 0; j < m_amplada; j++)
            matrix[i][j] = m_figura[i][j];
}
//---------------------------

// Funcio que detecta quin tipus de figura es vol crear i a partir d'aquesta informació genera la figura (la pinta, inicialitza els seus valors, etc.)
void Figura::crearFigura(TipusFigura nouFigura, int x, int y)
{
    m_tipus = nouFigura;
    m_color = (ColorFigura)nouFigura;
    m_x = x;
    m_y = y;

    ColorFigura matrix[MAX_HORITZONTAL][MAX_VERTICAL];

    for (int i = 0; i < MAX_HORITZONTAL; i++)
        for (int j = 0; j < MAX_VERTICAL; j++)
            matrix[i][j] = COLOR_NEGRE;
    
    switch (nouFigura) //No he pogut de moment mainstreamear tot en una sola funcio auxiliar, he hagut de fer 2, intentare per la entrega final minimitzar més aquesta funcio
    {
        case FIGURA_O:
            initFiguraDrecera2For(2, 2, matrix, 1);
                    
            break;

        case FIGURA_I:
            initFiguraDrecera(4, 4, matrix, 2);   
            break;

        case FIGURA_T:
            initFiguraDrecera(3, 3, matrix, 3);    
		    matrix[0][1] = COLOR_MAGENTA;
		    
            break;

        case FIGURA_L:
            initFiguraDrecera(3, 3, matrix, 4);     
            matrix[0][2] = COLOR_TARONJA; 
            
            break;

        case FIGURA_J:
            initFiguraDrecera(3, 3, matrix, 5);     
            matrix[0][0] = COLOR_BLAUFOSC;
            
            break;

        case FIGURA_Z:
            m_alcada = 3;
            m_amplada = 3;
            matrix[0][0] = COLOR_VERMELL;
            matrix[0][1] = COLOR_VERMELL;
            matrix[1][1] = COLOR_VERMELL;
            matrix[1][2] = COLOR_VERMELL;
            
            break;

        case FIGURA_S:
            m_alcada = 3;
            m_amplada = 3;
            matrix[0][1] = COLOR_VERD;
            matrix[0][2] = COLOR_VERD;
            matrix[1][0] = COLOR_VERD;
            matrix[1][1] = COLOR_VERD;
            
            break;
            
        case NO_FIGURA:
            m_alcada = 0;
            m_amplada = 0;
    }

    for (int i = 0; i < MAX_VERTICAL; i++)
        for (int j = 0; j < MAX_HORITZONTAL; j++)
            m_figura[i][j] = matrix[i][j];
}

//Funcions Privades Auxiliars de creaFigura
void Figura::initFiguraDrecera(int vertical, int horitzontal, ColorFigura matrix[][MAX_HORITZONTAL], int color)
{
    m_alcada = vertical;
    m_amplada = horitzontal;

    int colorInt = static_cast<int>(color);

    for (int i = 0; i < vertical; i++)
            matrix[1][i] = static_cast<ColorFigura>(colorInt);
}

void Figura::initFiguraDrecera2For(int vertical, int horitzontal, ColorFigura matrix[][MAX_HORITZONTAL], int color)
{
    m_alcada = vertical;
    m_amplada = horitzontal;

    int colorInt = static_cast<int>(color);

    for (int i = 0; i < vertical; i++)
        for (int j = 0; j < horitzontal; j++)
            matrix[i][j] = static_cast<ColorFigura>(colorInt);
}
//----------
//---------------------------

//Funcio que fa girar la figura, ja sigui en sentit horari o antihorari, depentent del que es pasi en el parametre "gir" de la funcio girar
void Figura::gir(DireccioGir gir)
{
    transposada();

    ColorFigura matrix[MAX_HORITZONTAL][MAX_VERTICAL];
    
    if (gir == GIR_HORARI)
        invertir(matrix, 1);
    else
        invertir(matrix, 0);
    
    for (int i = 0; i < MAX_VERTICAL; i++)
        for (int j = 0; j < MAX_HORITZONTAL; j++)
            m_figura[i][j] = matrix[i][j]; 
}



//Funcions Privades Auxiliars per girar la figura, ni han d'altres en joc.cpp i tauler.cpp per comprovar que la figura giri
void Figura::transposada()
{
	ColorFigura matrix[MAX_VERTICAL][MAX_HORITZONTAL];
	for (int i = 0; i < m_alcada; i++)
		for (int j = 0; j < m_amplada; j++)
			matrix[i][j] = m_figura[j][i];

	for (int i = 0; i < m_alcada; i++)
		for (int j = 0; j < m_amplada; j++)
			m_figura[i][j] = matrix[i][j];
}

void Figura::invertir(ColorFigura matrix[][MAX_HORITZONTAL], bool filCol)
{
    ColorFigura t;
        
    for (int i = 0; i < MAX_HORITZONTAL; i++)
        for (int j = 0; j < MAX_HORITZONTAL; j++)
            matrix[i][j] = m_figura[i][j];
    
    if (filCol)
    {
        for (int i = 0; i < m_alcada; i++)
        {
            int meitat = m_amplada / 2;
            
            for (int j = 0; j < meitat; j++)
            {
                t = matrix[i][j];
                matrix[i][j] = matrix[i][m_amplada - 1 - j];
                matrix[i][m_amplada - 1 - j] = t;
            }
        }
    }
    else
    {
    
        for (int j = 0; j < m_amplada; j++)
        {
            int meitat = m_alcada / 2;
        
            for (int i = 0; i < meitat; i++)
            {
                t = matrix[i][j];
                matrix[i][j] = matrix[m_alcada - 1 - i][j];
                matrix[m_alcada - 1 - i][j] = t;
            }
        }

    }
}
//----------
//---------------------------