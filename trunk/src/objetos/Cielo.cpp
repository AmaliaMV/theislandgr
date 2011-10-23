/*
 * Cielo.cpp
 *
 *  Created on: 17/09/2011
 *      Author: amalia
 */

#include "Cielo.h"

Cielo::Cielo( string nombreTextura, float radio ): ObjetoDibujable ( new Textura24(nombreTextura))
{
	this->radio = radio;
	this->titaMax = 360.0;
	this->fiMax = 90.0;
	this->deltaTita = 20;
	this->deltaFi = 20;

	this->displayList();
}

Cielo::~Cielo()
{
}

void Cielo::displayList()
{
	float *ptos, *coordText;
	unsigned int cantPtosX, cantPtosY;
	GLuint *vertIndice;

	cantPtosX = floor(deltaTita) + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = floor(deltaFi) + 1;

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

void Cielo::generarFigura ( float *ptos, unsigned int *vertIndice )
{
	float titaAvance, fiAvance;
	unsigned int cantPtosX, cantPtosY;

	titaAvance = titaMax / deltaTita;
	fiAvance = fiMax / deltaFi;

	cantPtosX = floor(deltaTita) + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = floor(deltaFi) + 1;

	/*asigno las coordenadas*/
	generarPtos ( ptos, titaAvance, fiAvance );

	/*asingo el orden de los indices*/
	setIndice ( (cantPtosY-1)*cantPtosX*2, 3*cantPtosX, vertIndice );
}

void Cielo::generarPtos ( float *ptos, float titaAvance, float fiAvance )
{
	unsigned int posPto = 0;

	for (float fi = 0 ; fi <= fiMax; fi += fiAvance)
	{
		for (float tita = 0 ; tita <= titaMax; tita += titaAvance, posPto += CteObjeto::CANT_COORD_PTO)
		{
			ptos[posPto    ] = radio * Matematica::cosHex ( tita ) * Matematica::sinHex ( fi );
			ptos[posPto + 1] = radio * Matematica::sinHex ( tita ) * Matematica::sinHex ( fi );
			ptos[posPto + 2] = radio * Matematica::cosHex ( fi );
		}
	}
}

void Cielo::setIndice ( float indiceMax, unsigned int ptosPorFila, unsigned int *vertIndice )
{
	unsigned int posPto = 0;

	for (unsigned int posIndice = 0; posIndice < indiceMax; posIndice += 2, posPto += CteObjeto::CANT_COORD_PTO)
	{
		vertIndice[posIndice] = posPto / 3;
		vertIndice[posIndice+1] = (posPto + ptosPorFila)/3; // el siguiente pto ya q usamos triangle strip
	}
}

void Cielo::generarCoordText ( float *coordText, unsigned int cantFila, unsigned int cantColum )
{
	float pasoX, pasoY;
	unsigned int indice;

	pasoX = 1.0 / cantFila;
	pasoY = 1.0 / cantColum;

	for (unsigned int col = 0 ; col < cantColum; col ++)
	{
		for (unsigned int fil = 0 ; fil < cantFila; fil ++)
		{
			indice = fil * CteObjeto::CANT_COORD_TEXTURA + col * cantFila * CteObjeto::CANT_COORD_TEXTURA;
			coordText[indice] = pasoX * fil;
			coordText[indice + 1] = pasoY * col;
		}
	}
}
