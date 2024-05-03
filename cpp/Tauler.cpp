#include "Tauler.h"

//construcotr de tauler
Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = COLOR_NEGRE;
		}
	}
}
//---------------------------

//funcio que et "retorna" en la matriu "matrix" que es pasa per referencia la matriu del tauler i tambe "retorna" el el parametre figura "figura" que es pasa per referencia 
//les "stats" de la figura
void Tauler::getTauler(ColorFigura matrix[MAX_FILA][MAX_COL], Figura& figura)
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			matrix[i][j] = m_tauler[i][j];
		}
	}

	int cordX = figura.getX();
	int cordY = figura.getY();
	int amplada = figura.getHoritzontal();
	int alcada = figura.getVertical();
	

	for (int i = 0; i < alcada; i++)
	{
		for (int j = 0; j < amplada; j++)
	    {
			if (figura.getColor(i, j) != COLOR_NEGRE)
			{
				matrix[i + cordY][j + cordX] = figura.getColor(i, j);
			}
	    }
	}
}
//---------------------------

//funcio que comproba que la figura pasada per referencia no colisioni amb altres objectes del joc, fa servir la funico comprovaXoc (esta a tauler.h) per fer-ho, retorna un bool,
//0 no xoca, 1 xoca
bool Tauler::xoca(Figura& figura) const
{
	int x = figura.getX();
	int y = figura.getY();
	
	bool xoca = false;
	int amplada = figura.getHoritzontal();
	int alcada = figura.getVertical();
	for (int i = 0; i < alcada; i++)
	{
		int j = 0;
		while (j < amplada && !xoca)
		{
			xoca = comprovaXoc(i, j, x, y, figura);
			j++;
		}
	}
	
	return xoca;
}
//---------------------------

//elimina les files senceres del tauler i retorna el nombre de files que ha eliminat
int Tauler::eliminaFila()
{
	int filesSenceres = 0;

	for (int i = 0; i < MAX_FILA; i++)
	{
		bool filaSencera = false;
		int j = 0;
		while (j < MAX_COL && !filaSencera)
		{
			if (m_tauler[i][j] == COLOR_NEGRE)
			{
				filaSencera = true;
			}
			else
			{
				j++;
			}
		}
		
		if (!filaSencera)
		{
			for (int k = i; k > 0; k--) 
			{
				for (int j = 0; j < MAX_FILA; j++)
				{
				    m_tauler[k][j] = m_tauler[k - 1][j];
				}
			}
			
            for (int j = 0; j < MAX_COL; j++)
            {
				m_tauler[0][j] = COLOR_NEGRE;
            }
			    
			filesSenceres++;
		}
	}

	return filesSenceres;
}