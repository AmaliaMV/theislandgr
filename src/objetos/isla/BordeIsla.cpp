/*
 * BordeIsla.cpp
 *
 *  Created on: 12/08/2011
 *      Author: amalia
 */

/* tod0 lo relacionado con la textura solo va a funcionar bien si
	 * el xmin y el ymin son menores a cero de forma tal que al
	 * multiplicar estos valores por un numero positivo, el resultado
	 * obtenido sea menor a ellos
	 */

#include "BordeIsla.h"

const float BordeIsla::PENDIENTE = 0.09;  // es el escalado q hay entre una curva y la q sigue. No puede ser un numero menor a uno
const float BordeIsla::ESCALADOxy = 20.0;
const float BordeIsla::ESCALADOz =  BordeIsla::ESCALADOxy / 9.00;
const float BordeIsla::ALTURA_ENTRE_NIVELES = 0.4;

BordeIsla::BordeIsla( PuntosControl *ptos, string nombreTextura, const int paso, const int cantNivelesHorizontales ) :ObjetoDibujable ( new Textura24(nombreTextura) )
{
	this->superficie = new BordeBSpline ( ptos, cantNivelesHorizontales, ESCALADOxy, ESCALADOz, PENDIENTE, ALTURA_ENTRE_NIVELES );

	this->displayList();
}

BordeIsla::~BordeIsla()
{
	delete superficie;
}

float BordeIsla::getAlturaMax()
{
	return this->superficie->getAltura();
}
float BordeIsla::getEscalado()
{
	return ESCALADOxy;
}
void BordeIsla::displayList()
{
	float *ptos, *coordText;
	unsigned int *indice;

	ptos = this->superficie->generarPtos();
	coordText = this->superficie->generarCoorText();
	indice = this->superficie->generarIndice();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, coordText);

			glNewList( this->getIdDisplayList(), GL_COMPILE);
			Textura::habilitar();
			this->getTextura()->usar();
			glColor3f(1.0, 1.0, 1.0);
			glDrawElements (GL_TRIANGLE_STRIP, superficie->getCantReferencias(), GL_UNSIGNED_INT, indice);
			Textura::deshabilitar();
			glEndList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete [] ptos;
	delete [] coordText;
	delete [] indice;
}
