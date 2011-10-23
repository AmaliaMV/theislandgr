/*
 * PisoDeBarco.cpp
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#include "PisoDeBarco.h"

const unsigned int PisoDeBarco::cantPasosTita = 20;

PisoDeBarco::PisoDeBarco(string nombreTextura):ObjetoDibujable( new Textura24( nombreTextura ) )
{
	this->displayList();
}

PisoDeBarco::~PisoDeBarco(){}

void PisoDeBarco::displayList()
{
	float *ptos, *coordText;
	unsigned int cantPtosX;
	GLuint *vertIndice;

	cantPtosX = cantPasosTita + 2; // el +1 es por el pto del medio +1 por <= en el angulo

	ptos = new float [CteObjeto::CANT_COORD_PTO * cantPtosX];
	vertIndice = new unsigned int [cantPtosX];
	coordText = new float [CteObjeto::CANT_COORD_TEXTURA * cantPtosX];
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
				glDrawElements (GL_TRIANGLE_FAN, cantPtosX, GL_UNSIGNED_INT, vertIndice);
				Textura::deshabilitar();
			glEndList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete []ptos;
	delete []vertIndice;
	delete []coordText;

}

void PisoDeBarco::generarPtos(float *ptos)
{
	float tita, pasoTita;
	unsigned int pto = 0;

	pasoTita = ( CteBarco::titaMax - CteBarco::titaMin )/ cantPasosTita;

	ptos [pto    ] = 0.0;
	ptos [pto + 1] = 0.0;
	ptos [pto + 2] = 0.0;

	pto += CteObjeto::CANT_COORD_PTO;

	for ( tita = CteBarco::titaMin; tita <= CteBarco::titaMax; tita += pasoTita, pto += CteObjeto::CANT_COORD_PTO )
	{
		ptos [pto    ] = CteBarco::radioX * Matematica::cosHex( tita );
		ptos [pto + 1] = CteBarco::radioY * Matematica::sinHex( tita );
		ptos [pto + 2] = 0.0;
	}
}

void PisoDeBarco::setIndice(float indiceMax, unsigned int *vertIndice)
{
	unsigned int pto;

	vertIndice [0 ] = 0.0;

	for ( pto = 1; pto < indiceMax; pto ++ )
		vertIndice [pto] = pto;

}

void PisoDeBarco::generarCoordText(float *coordText, unsigned int cantFila)
{
	float tita, pasoTita, centro = 0.5;
	unsigned int pto = 0;

	pasoTita = ( CteBarco::titaMax - CteBarco::titaMin )/ cantPasosTita;

	coordText [pto    ] = centro;
	coordText [pto + 1] = centro;

	pto += CteObjeto::CANT_COORD_TEXTURA;

	for ( tita = CteBarco::titaMin; tita <= CteBarco::titaMax; tita += pasoTita, pto += CteObjeto::CANT_COORD_TEXTURA )
	{
		coordText [pto    ] =  CteBarco::radioX / CteBarco::radioY * Matematica::cosHex( tita ) + centro;
		coordText [pto + 1] =  Matematica::sinHex( tita ) + centro;
	}
}
