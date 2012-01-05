/*
 * Agua.cpp
 *
 *  Created on: 11/09/2011
 *      Author: amalia
 */


#include "Agua.h"

const float Agua::ANG_XY_MAX = 360.0;
const float Agua::COORD_CENTRO_TEXTURA = 0.5;
const float Agua::GRADO_AGUA_AGITADA = 0.75;

Agua::Agua( string nombreTextura, float radio )
{
	this->angulo = 0.0;

	this->RADIO = radio;
	this->textura = new Textura24(nombreTextura);

}

void Agua::incrementarAngulo()
{
	angulo += GRADO_AGUA_AGITADA;
	if ( angulo >= ANG_XY_MAX )
		angulo = 0;
}

void Agua::dibujar()
{
	float *ptos, *coordText;
	GLuint *vertIndice;
	const unsigned int ptosHorizontales = PASO_ANGULO_XY + 1 ; // el +1 es por el 360
	const unsigned int ptosVerticales = PASO_RADIO + 1 ;		// el +1 es porq cuento 0.0 tmb
	const unsigned int cantPtos = ptosVerticales * ptosHorizontales;
	/*
	 * los ptos de los extremos q son ptosHorizontales  ptos los tengo q referenciar una vez
	 * los ptos del medio, o sea, ptosVerticales-2 , 2 veces cada uno
	 * despues, un costado lo tengo q referenciar una vez mas por eso el + 1
	 */
	const unsigned int cantRef = 2 * ( ptosHorizontales + 1 ) * ( ptosVerticales - 1 );

	ptos = new float [ CteObjeto::CANT_COORD_PTO * cantPtos ];
	vertIndice = new unsigned int [ cantRef ]; //cant de veces q tengo q hacer referencias a los ptos
	coordText = new float [ CteObjeto::CANT_COORD_TEXTURA * cantPtos ];

	this->generarPtos( ptos );
	this->setIndice( vertIndice, ptosHorizontales, ptosVerticales );
	this->generarCoordText( coordText, cantPtos );

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, coordText);

			Textura::habilitar();
			this->textura->usar();
			glColor3f(1.0, 1.0, 1.0);
			glDrawElements (GL_TRIANGLE_STRIP/*GL_LINE_STRIP*/, cantRef, GL_UNSIGNED_INT, vertIndice);
			Textura::deshabilitar();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete []ptos;
	delete []vertIndice;
	delete []coordText;

}

Agua::~Agua() { }

void Agua::generarPtos ( float *ptos )
{
	float radio, anguloXY, anguloZ;
	unsigned int posPto = 0;

	anguloZ = angulo;

	for ( radio = 0.0; radio <= this->RADIO; radio+= this->getIncRadio() )
	{
		for ( anguloXY = 0.0 ; anguloXY <= ANG_XY_MAX; anguloXY += this->getIncAnguloXY() )
		{
			ptos[posPto    ] = radio * Matematica::cosHex ( anguloXY );
			ptos[posPto + 1] = radio * Matematica::sinHex ( anguloXY );
			ptos[posPto + 2] = 0.5 * Matematica::cosHex( anguloZ ) ; // -0.5 <= z<= 0.5

			posPto += CteObjeto::CANT_COORD_PTO;
		}

		anguloZ += this->getIncAnguloZ();
	}
}

void Agua::setIndice ( unsigned int *vertIndice, unsigned int ptosHorizontales, unsigned int ptosVerticales )
{
	unsigned int pos, posFila, posColumna;

	pos = 0;

	for ( posFila = 0; posFila < ptosVerticales - 1 ; posFila++ )
	{
		for ( posColumna = 0 ; posColumna < ptosHorizontales; posColumna++, pos+= 2 )
		{
			vertIndice[pos    ] = posColumna + ptosHorizontales * posFila;
			vertIndice[pos + 1] = posColumna + ptosHorizontales * ( posFila + 1);
		}

		vertIndice[pos    ] = ptosHorizontales * posFila;
		vertIndice[pos + 1] = ptosHorizontales * ( posFila + 1);
		pos += 2;
	}
}

void Agua::generarCoordText ( float *coordText, unsigned int cantPtos )
{
	float radio, anguloXY, radioCentrado;
	unsigned int posPto = 0;

	for ( radio = 0.0; radio <= this->RADIO; radio+= this->getIncRadio() )
	{
		radioCentrado = radio / ( this->RADIO * 2 ); // para q el radio qde entre 0.0 y 0.5
		for ( anguloXY = 0.0 ; anguloXY <= ANG_XY_MAX; anguloXY += this->getIncAnguloXY() )
		{
			coordText[posPto++] = radioCentrado * Matematica::cosHex ( anguloXY ) + COORD_CENTRO_TEXTURA; // para q las coordenadas de la textura esten entre 0 y 1
			coordText[posPto++] = radioCentrado * Matematica::sinHex ( anguloXY ) + COORD_CENTRO_TEXTURA;
		}
	}
}

const float Agua::getIncRadio() const
{
	return 	this->RADIO / PASO_RADIO;
}

const float Agua::getIncAnguloXY() const
{
	return 360.0 / PASO_ANGULO_XY;
}

const float Agua::getIncAnguloZ() const
{
	return CANT_CURVA * 360 ;
}
