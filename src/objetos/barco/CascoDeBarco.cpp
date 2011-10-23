/*
 * CascoDeBarco.cpp
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#include "CascoDeBarco.h"

const int CascoDeBarco::cantPasosFi 		= 20.0;
const int CascoDeBarco::cantPasosTita 	= 20.0;

CascoDeBarco::CascoDeBarco( string nombreTextura ):ObjetoDibujable( new Textura24( nombreTextura ) )
{
	this->displayList();
}

void CascoDeBarco::displayList()
{
	float *ptos, *coordText;
	unsigned int cantPtosX, cantPtosY;
	GLuint *vertIndice;

	cantPtosX = cantPasosTita + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = cantPasosFi + 1;

	ptos = new float [ CteObjeto::CANT_COORD_PTO *cantPtosX*cantPtosY];
	vertIndice = new unsigned int [(cantPtosY-1)*cantPtosX*2]; //cant de veces q tengo q hacer referencias a los ptos
	coordText = new float [CteObjeto::CANT_COORD_TEXTURA *cantPtosX*cantPtosY];
	this->generarFigura( ptos, vertIndice );
	this->generarCoordText( coordText, cantPtosX, cantPtosY);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, coordText);

			glNewList(this->getIdDisplayList(), GL_COMPILE);
				glColor3f (1.0, 1.0, 1.0);
				Textura::habilitar();
				this->getTextura()->usar();
				glDrawElements (GL_TRIANGLE_STRIP, (cantPtosY-1)*cantPtosX*2, GL_UNSIGNED_INT, vertIndice);
				Textura::deshabilitar();
			glEndList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete []ptos;
	delete []vertIndice;
	delete []coordText;

}

void CascoDeBarco::generarFigura ( float *ptos, unsigned int *vertIndice )
{
	unsigned int cantPtosX, cantPtosY;

	cantPtosX = cantPasosTita + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = cantPasosFi + 1;

	generarPtos ( ptos );
	setIndice ( (cantPtosY-1)*cantPtosX*2, 3*cantPtosX, vertIndice );
}

/* es un elipsoide */
void CascoDeBarco::generarPtos ( float *ptos )
{
	float tita, fi, pasoFi, pasoTita;
	unsigned int pto = 0;

	pasoFi = ( CteBarco::fiMax - CteBarco::fiMin ) / cantPasosFi;
	pasoTita = ( CteBarco::titaMax - CteBarco::titaMin )/ cantPasosTita;

	for ( fi = CteBarco::fiMin; fi <= CteBarco::fiMax; fi+= pasoFi )
	{
		for ( tita = CteBarco::titaMin; tita <= CteBarco::titaMax; tita += pasoTita, pto += CteObjeto::CANT_COORD_PTO )
		{
			ptos [pto    ] = CteBarco::radioX * Matematica::cosHex( fi ) * Matematica::cosHex( tita );
			ptos [pto + 1] = CteBarco::radioY * Matematica::cosHex( fi ) * Matematica::sinHex( tita );
			ptos [pto + 2] = CteBarco::radioZ * Matematica::sinHex( fi );
		}
	}
}

void CascoDeBarco::setIndice ( float indiceMax, unsigned int ptosPorFila, unsigned int *vertIndice )
{
	unsigned int posPto = 0;

	for (unsigned int posIndice = 0; posIndice < indiceMax; posIndice += 2, posPto += CteObjeto::CANT_COORD_PTO)
	{
		vertIndice[posIndice] = posPto / 3;
		vertIndice[posIndice+1] = (posPto + ptosPorFila)/3; // el siguiente pto ya q usamos triangle strip
	}

}

void CascoDeBarco::generarCoordText ( float *coordText, unsigned int cantFila, unsigned int cantColum )
{
	unsigned int indice = 0, repetir = 3;

	for (unsigned int fil = 0 ; fil < cantFila; fil ++)
	{
		for (unsigned int col = 0 ; col < cantColum; col ++)
		{
			coordText[indice    ] = (float) fil / cantFila ;
			coordText[indice + 1] = repetir * (float) col / cantColum ;
			indice += 2;

		}
	}
}

CascoDeBarco::~CascoDeBarco() { }
