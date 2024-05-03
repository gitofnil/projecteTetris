#include "Joc.h"

//inicialitzador de totes les variables del joc, les posa al seu estat "dafault"
void Joc::inicialitza(const string& nomFitxer) 
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    
    if (!fitxer.is_open())
        cout << "Fitxer " << nomFitxer << " no s'ha trobat" << endl; 
    else
    {
        int tipus, fila, columna, gir;
        
        fitxer >> tipus >> fila >> columna >> gir;
        
        m_figura.setX(columna - 1);
        m_figura.setY(fila - 1);
        m_figura.crearFigura((TipusFigura)tipus, columna - 1, fila - 1);

        for (int i = 0; i < gir; i++)
            m_figura.gir(GIR_HORARI);

        int color;
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer >> color;
                m_tauler.setColor(i, j, (ColorFigura)color);
            }
        }
        
    }
    
    fitxer.close();
}
//---------------------------

//funcio que gira la figura, per tal de fer-ho demana informacio de si es xoca la figura amb parts de la grid del joc o amb altres figures
bool Joc::giraFigura(DireccioGir direccio)
{
	Figura figura = m_figura;
    bool gira = false;

    figura.gir(direccio);
    gira = m_tauler.xoca(figura);

    if (!gira)
        m_figura.gir(direccio);
        
    return gira;
}
//---------------------------

//Funcio que fa que baixi la figura en questio una casella cada vegada sempre i cuant no es xoqui contra elguna cosa (bordes o altres peces)
int Joc::baixaFigura() 
{
    bool xoca;
    
    Figura figura = m_figura;
    figura.baixaFila();
    xoca = m_tauler.xoca(figura);

    if(!xoca)
        m_figura.baixaFila();

    else
    {
        ColorFigura matrix[MAX_VERTICAL][MAX_HORITZONTAL];
        m_figura.getMatrix(matrix);
        
        int x, y, horitzontal, vertical;

        x = m_figura.getX();
        y = m_figura.getY();
        vertical = m_figura.getVertical();
        horitzontal = m_figura.getHoritzontal();

        for (int i = 0; i < vertical; i++)
            for (int j = 0; j < horitzontal; j++)
                if (matrix[i][j] != COLOR_NEGRE)
                    m_tauler.setColor(y + i, x + j, matrix[i][j]);
                    
        m_figura.crearFigura(NO_FIGURA, 0, 0);
        return m_tauler.eliminaFila();
    }
    
    return 0;
}
//---------------------------

//funcio que mou la figura cap a la dreta o esquerra depenent del que se li indiqui a dirX
bool Joc::mouFigura(int dirX)
{
    Figura figAux = m_figura;
    figAux.mouHoritzontal(dirX);
    bool mov = false;

    if(!m_tauler.xoca(figAux))
    {
        m_figura.mouHoritzontal(dirX);
        mov = true;
    }
        
    return mov;
}
//---------------------------

//Funcio que escriu el tauler en el fitxer de sortida
void Joc::escriuTauler(const string& nomFitxer) 
{

    ofstream fitxer;
    fitxer.open(nomFitxer);

    if(fitxer.is_open())
    {
        ColorFigura taulerAct[MAX_FILA][MAX_COL];
        m_tauler.getTauler(taulerAct, m_figura);

        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
                fitxer << taulerAct[i][j] << " ";
                
            fitxer << endl;
        }
    }
    
    fitxer.close();
}
//---------------------------
