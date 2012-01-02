/*
 * ToroideConTextura.cpp
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#include "ToroideConTextura.h"

ToroideConTextura::ToroideConTextura(string nombreTextura, float radioXY, float radioZ)
	: ODTextura ( new Textura24 ( nombreTextura ) )
{
	this->RADIO_XY = radioXY;
	this->RADIO_Z = radioZ;

	this->init( PASO_XY * PASO_Z,
			( 2 + 2 * PASO_XY ) * ( PASO_Z - 1 ) + 2 * PASO_Z + 2,
			GL_TRIANGLE_STRIP );
}

ToroideConTextura::~ToroideConTextura() { }

void ToroideConTextura::generarCoordPtos()
{
	unsigned int indice = 0;
	float alfa, pasoAlfa, beta, pasoBeta;

	pasoAlfa = GIRO_COMPLETO / PASO_Z;
	pasoBeta = GIRO_COMPLETO / PASO_XY;

	for ( alfa = 0 ; alfa < GIRO_COMPLETO; alfa += pasoAlfa )
	{
		for ( beta = 0 ; beta < GIRO_COMPLETO; beta += pasoBeta )
		{
			this->ptos[indice++] = ( RADIO_XY + RADIO_Z * Matematica::cosHex( alfa ) ) * Matematica::cosHex( beta );
			this->ptos[indice++] = ( RADIO_XY + RADIO_Z * Matematica::cosHex( alfa ) ) * Matematica::sinHex( beta );
			this->ptos[indice++] = RADIO_Z * Matematica::sinHex( alfa );
		}
	}
}
void ToroideConTextura::generarIndice()
{
	unsigned int indice = 0, alto, ancho;

	for ( alto = 0; alto < PASO_Z - 1; alto++ )
	{
		for ( ancho = 0; ancho < PASO_XY; ancho++ )
		{
			this->indice[indice++] = ancho + alto * PASO_XY;
			this->indice[indice++] = ancho + ( alto + 1 ) * PASO_XY;
		}

		this->indice[indice++] = alto * PASO_XY;
		this->indice[indice++] = ( alto + 1 ) * PASO_XY;
	}

	for ( ancho = 0; ancho < PASO_XY; ancho++ )
	{
		this->indice[indice++] = ancho + ( PASO_Z - 1 ) * PASO_XY;
		this->indice[indice++] = ancho;
	}

	this->indice[indice++] = ( PASO_Z - 1 ) * PASO_XY;
	this->indice[indice++] = 0;

}
void ToroideConTextura::generarCoodText()
{
	unsigned int indice = 0, alfa, beta;

	for ( alfa = 0 ; alfa < PASO_Z; alfa++ )
	{
		for ( beta = 0 ; beta < PASO_XY; beta ++ )
		{
			this->text[indice++] = alfa * 1.0 / PASO_XY;
			this->text[indice++] = beta * 1.0 / PASO_Z;
		}
	}
}
