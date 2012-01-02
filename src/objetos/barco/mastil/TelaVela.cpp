/*
 * Vela.cpp
 *
 *  Created on: 22/12/2011
 *      Author: amalia
 */

#include "TelaVela.h"
/*
 * tener en cuenta que el valor de
 * Vela::CANT_PTOS_LARGO y Vela::CANT_PTOS_ALTO
 * puede producir un error de redondeo al calcular
 * incU e incV y hace q el programa aborte
 *
 */

const unsigned int TelaVela::CANT_PTOS_LARGO = 30;
const unsigned int TelaVela::CANT_PTOS_ALTO = 30;

TelaVela::TelaVela(	string nombreTextura, float largo, float alto, float factCurvatura)
	:ODTextura( new Textura24(nombreTextura) )
{
	this->LARGO = largo;
	this->ALTO = alto;
	this->FACTOR_CURVATURA = factCurvatura;

	this->init(CANT_PTOS_LARGO * CANT_PTOS_ALTO,
			2 * (CANT_PTOS_ALTO - 1) * CANT_PTOS_LARGO - ( CANT_PTOS_ALTO - 2) ,
			GL_TRIANGLE_STRIP);
}

TelaVela::~TelaVela(){}

void TelaVela::generarCoordPtos ()
{
	/*nV y nU son para evitar el error de redondeo*/
	unsigned int indice = 0, nV=0, nU=0;
	double  u, v, incU, incV, Vmax;

	incU = LARGO / CANT_PTOS_LARGO;
	incV = ALTO / CANT_PTOS_ALTO;

	v = -ALTO / 2;
	Vmax = FACTOR_CURVATURA * pow (v, 2); //esto es para q me qde los extremos en el eje 0

	for ( nV = 0; nV < CANT_PTOS_ALTO; nV++, v += incV)
	{
		for ( nU = 0, u = 0; nU < CANT_PTOS_LARGO; nU++, u += incU )
		{
			ptos[indice++] = FACTOR_CURVATURA * pow (v, 2) - Vmax;
			ptos[indice++] = u;
			ptos[indice++] = v;
		}
	}

//	cout<<"indice: "<<indice<<endl;
}

void TelaVela::generarIndice ()
{
	/* Para Cant ptos: 5x5
	 * 20	21	22	23	24
	 * 15	16	17	18	19
	 * 10	11	12	13	14
	 * 5	6	7	8	9
	 * 0	1	2	3	4
	 *
	 * salida:
	 * a)
	 * 0	5	1	6
	 * 2	7	3	8
	 * 4	9
	 * b)
	 * 14	8	13	7
	 * 12	6	11	5
	 * 10
	 * c)
	 * 15	11	16	12
	 * 17	13	16	14
	 * 19
	 * d)
	 * 24	18	23	17
	 * 22	16	21	15
	 * 20
	 */
	unsigned int pos = 0, v;
	int u;

	//a)
	for ( u = 0; (unsigned int)u < CANT_PTOS_LARGO; u++ )
	{
		indice[pos++] = u;
		indice[pos++] = CANT_PTOS_LARGO + u;
	}

	for ( v = 1; v < CANT_PTOS_ALTO - 1; v++ )
	{
		//b), d)
		for ( u = CANT_PTOS_LARGO - 1; u > 0; u-- )
		{
			indice[pos++] = (v+1) * CANT_PTOS_LARGO + u;
			indice[pos++] = v * CANT_PTOS_LARGO + u - 1 ;
		}

		indice[pos++] = (v+1) * CANT_PTOS_LARGO + u;

		v++;
		if ( v >= CANT_PTOS_ALTO - 1)
			break;

		//c)
		for ( u = 0; (unsigned int)u < CANT_PTOS_LARGO - 1; u++ )
		{
			indice[pos++] = (v+1) * CANT_PTOS_LARGO + u;
			indice[pos++] = v * CANT_PTOS_LARGO + u + 1;
		}

		indice[pos++] = (v+1) * CANT_PTOS_LARGO + u;
	}
}
void TelaVela::generarCoodText ()
{
	unsigned int indice = 0, nV, nU;
	double  u, v, incU, incV;

	incU = LARGO / CANT_PTOS_LARGO;
	incV = ALTO / CANT_PTOS_ALTO;

	for (  v = 0, nV = 0; nV < CANT_PTOS_ALTO; v += incV, nV++ )
	{
		for ( u = 0, nU = 0; nU < CANT_PTOS_LARGO; u += incU, nU++ )
		{
			text[indice++] = u / CANT_PTOS_LARGO;
			text[indice++] = v / CANT_PTOS_ALTO;
		}
	}
//	cout<<"indice_t: "<<indice<<endl;
}
