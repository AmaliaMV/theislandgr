/*
 * PaloDeBaranda.cpp
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#include "PaloDeBaranda.h"

const float PaloDeBaranda::alto = 2.0;
const float PaloDeBaranda::lado = 0.5;

PaloDeBaranda::PaloDeBaranda(string nombreTextura):ObjetoDibujable( new Textura24( nombreTextura ) )
{
	this->displayList();
}

PaloDeBaranda::~PaloDeBaranda(){ }

void PaloDeBaranda::displayList()
{
	float *ptos, *coordText;
	unsigned int cantPtosX;
	GLuint *vertIndice;

	cantPtosX = 10; // son la cant de ptos q va a tener el palito + 2 porq tengo q repetir 2 ptos

	ptos = new float [ CteObjeto::CANT_COORD_PTO * cantPtosX ];
	vertIndice = new unsigned int [ cantPtosX ]; //cant de veces q tengo q hacer referencias a los ptos
	coordText = new float [ CteObjeto::CANT_COORD_TEXTURA * cantPtosX ];
	this->generarPtos( ptos );
	this->setIndice( cantPtosX, vertIndice );
	this->generarCoordText( coordText, cantPtosX);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, coordText);

			glNewList(this->getIdDisplayList(), GL_COMPILE);
				glColor3f (1.0, 1.0, 1.0);
				Textura::habilitar();
				this->getTextura()->usar();
				glDrawElements (GL_TRIANGLE_STRIP, cantPtosX, GL_UNSIGNED_INT, vertIndice);
				Textura::deshabilitar();
			glEndList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete []ptos;
	delete []vertIndice;
	delete []coordText;

}

void PaloDeBaranda::generarCoordText(float *coordText, unsigned int cantFila)
{
	unsigned int altura, pto = 0;

	for ( altura = 0; altura <= alto; altura+= alto )
	{
		coordText [pto     ] =  0.0;
		coordText [pto + 1 ] = altura/alto;
		coordText += CteObjeto::CANT_COORD_TEXTURA;
		coordText [pto     ] = 0.25;
		coordText [pto + 1 ] = altura/alto;
		coordText += CteObjeto::CANT_COORD_TEXTURA;
		coordText [pto     ] = 0.50;
		coordText [pto + 1 ] = altura/alto;
		coordText += CteObjeto::CANT_COORD_TEXTURA;
		coordText [pto     ] = 0.75;
		coordText [pto + 1 ] = altura/alto;
		coordText += CteObjeto::CANT_COORD_TEXTURA;
		coordText [pto     ] = 1.00;
		coordText [pto + 1 ] = altura/alto;
		coordText += CteObjeto::CANT_COORD_TEXTURA;
	}
}



void PaloDeBaranda::generarPtos(float *ptos)
{
	unsigned int altura, pto = 0;

	for ( altura = 0; altura <= alto; altura+= alto )
	{
		ptos [pto     ] = lado/2;
		ptos [pto + 1 ] = -lado/2;
		ptos [pto + 2 ] = altura;
		pto += CteObjeto::CANT_COORD_PTO;
		ptos [pto     ] = lado/2;
		ptos [pto + 1 ] = lado/2;
		ptos [pto + 2 ] = altura;
		pto += CteObjeto::CANT_COORD_PTO;
		ptos [pto     ] = -lado/2;
		ptos [pto + 1 ] = lado/2;
		ptos [pto + 2 ] = altura;
		pto += CteObjeto::CANT_COORD_PTO;
		ptos [pto     ] = -lado/2;
		ptos [pto + 1 ] = -lado/2;
		ptos [pto + 2 ] = altura;
		pto += CteObjeto::CANT_COORD_PTO;
		ptos [pto     ] = lado/2;
		ptos [pto + 1 ] = -lado/2;
		ptos [pto + 2 ] = altura;
		pto += CteObjeto::CANT_COORD_PTO;
	}
}

void PaloDeBaranda::setIndice(float indiceMax, unsigned int *vertIndice)
{
	vertIndice [0 ] = 0;
	vertIndice [1 ] = 5;
	vertIndice [2 ] = 1;
	vertIndice [3 ] = 6;
	vertIndice [4 ] = 2;
	vertIndice [5 ] = 7;
	vertIndice [6 ] = 3;
	vertIndice [7 ] = 8;
	vertIndice [8 ] = 4;
	vertIndice [9 ] = 9;
}

float PaloDeBaranda::getLado()
{
	return this->lado;
}



