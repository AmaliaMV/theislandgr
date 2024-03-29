/*
 * Canon.cpp
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#include "Canon.h"

const float Canon::ANGV_CANON_MAX = 20.0;
const float Canon::ANGV_CANON_MIN = -20.0;
const float Canon::ANGH_CANON_MAX = 34.0;
const float Canon::ANGH_CANON_MIN = -34.0;

const float Canon::DELTA_ANG = 2.0; //encuenta disminuye o aumenta el ang cada vez q se inc o dec el angulo

Canon::Canon( string nombreText, string nombreArchPtos )
	:ODTextura( new Textura24(nombreText) )
{
	angV = 0.0;
	angH = 0.0;

	ptosCtrl = new PuntosControl();
	ArchivoPtosControl::cagarPtosControl( ptosCtrl, nombreArchPtos );

	CalculadoraBezier *bezierCubica = new CalculadoraBezier(GRADO_BEZIER);

	const unsigned int cantPtosH = FI_MAX / PASO_ROT_FI + 1; // cuento al 0 dos veces
	const unsigned int cantPtosV = bezierCubica->cantCurvas(ptosCtrl) * PASO_ROT_Z;
	delete bezierCubica;

	this->inicializarLuz();

	this->init(cantPtosH * cantPtosV, cantPtosH*(cantPtosV-1)*2, GL_TRIANGLE_STRIP, true);
}

Canon::~Canon()
{
	delete ptosCtrl;
	this->eliminarLuz();
}

void Canon::incAngV()
{
	if ( angV < ANGV_CANON_MAX )
		angV+= DELTA_ANG;
}
void Canon::decAngV()
{
	if ( angV > ANGV_CANON_MIN )
		angV-= DELTA_ANG;
}

void Canon::derecha()
{
	if ( angH < ANGH_CANON_MAX )
		angH+= DELTA_ANG;

}
void Canon::izquierda()
{
	if ( angH > ANGH_CANON_MIN )
		angH-= DELTA_ANG;
}

float Canon::getAngH() const
{
	return this->angH;
}

float Canon::getAngV() const
{
	return this->angV;
}

void Canon::generarCoordPtos()
{
	CalculadoraBezier *bezierCubica = new CalculadoraBezier(GRADO_BEZIER);
	float ro0, fi, z0;
	unsigned int pos=0;
	const unsigned int cantCurvas = bezierCubica->cantCurvas(ptosCtrl);
	GLfloat puntos[GRADO_BEZIER+1][CteObjeto::CANT_COORD_PTO];

	for (unsigned int i = 0; i < cantCurvas; i++)
	{
		for (unsigned int j = 0; j < GRADO_BEZIER+1; j++)
		{
			for (unsigned int k = 0; k < CteObjeto::CANT_COORD_PTO; k++)
				puntos[j][k] = ptosCtrl->getPtos()[j*CteObjeto::CANT_COORD_PTO+i*CteObjeto::CANT_COORD_PTO*GRADO_BEZIER + k];
		}

		for (unsigned int k = 0; k < PASO_ROT_Z; k++)
		{
			bezierCubica->f_bezierCentrada05(*puntos, (float)k/PASO_ROT_Z, ro0, z0);

			for (fi = FI_MIN; fi <= FI_MAX; fi+=PASO_ROT_FI )
			{
				ptos[pos++] = ro0 * Matematica::cosHex(fi);
				ptos[pos++] = ro0 * Matematica::sinHex(fi);
				ptos[pos++] = z0;
			}
		}
	}
	delete bezierCubica;
}
void Canon::generarIndice()
{
	CalculadoraBezier *bezierCubica = new CalculadoraBezier(GRADO_BEZIER);
	float fi;
	unsigned int pos = 0, ptoAcutal = 0;
	const unsigned int cantCurvas = bezierCubica->cantCurvas(ptosCtrl),
			cantPtosH = FI_MAX / PASO_ROT_FI + 1; // cuento al 0 dos veces;
	delete bezierCubica;


	for (unsigned int i = 0; i < cantCurvas-1; i++)
		for (unsigned int k = 0; k < PASO_ROT_Z; k++)
			for (fi = FI_MIN; fi <= FI_MAX; fi+=PASO_ROT_FI, ptoAcutal++)
			{
				indice[pos++] = ptoAcutal;
				indice[pos++] = ptoAcutal + cantPtosH;
			}

	//para el ultimo tramo de curva:
	for (unsigned int k = 0; k < PASO_ROT_Z-1; k++)
		for (fi = FI_MIN; fi <= FI_MAX; fi+=PASO_ROT_FI, ptoAcutal++)
		{
			indice[pos++] = ptoAcutal;
			indice[pos++] = ptoAcutal + cantPtosH;
		}
}
void Canon::generarCoodText()
{
	CalculadoraBezier *bezierCubica = new CalculadoraBezier(GRADO_BEZIER);
	float ro0, fi, z0;
	unsigned int pos=0;
	const unsigned int cantCurvas = bezierCubica->cantCurvas(ptosCtrl);
	GLfloat puntos[GRADO_BEZIER+1][CteObjeto::CANT_COORD_PTO];

	for (unsigned int i = 0; i < cantCurvas; i++)
	{
		for (unsigned int j = 0; j < GRADO_BEZIER+1; j++)
		{
			for (unsigned int k = 0; k < CteObjeto::CANT_COORD_PTO; k++)
				puntos[j][k] = ptosCtrl->getPtos()[j*CteObjeto::CANT_COORD_PTO+i*CteObjeto::CANT_COORD_PTO*GRADO_BEZIER + k];
		}

		for (unsigned int k = 0; k < PASO_ROT_Z; k++)
		{
			bezierCubica->f_bezierCentrada05(*puntos, (float)k/PASO_ROT_Z, ro0, z0);

			for (fi = FI_MIN; fi <= FI_MAX; fi+=PASO_ROT_FI )
			{
				text[pos++] = (1.0-(i*PASO_ROT_Z+(float)k)/PASO_ROT_Z/cantCurvas);
				text[pos++] = (1.0-fi/FI_MAX)+0.5;
			}
		}
	}

	delete bezierCubica;
}

void Canon::generarNormales()
{
	CalculadoraBezier *bezierCubica = new CalculadoraBezier(GRADO_BEZIER);
	float fi;
	unsigned int pos=0;
	const unsigned int cantCurvas = bezierCubica->cantCurvas(ptosCtrl);

	for (unsigned int i = 0; i < cantCurvas; i++)
	{
		for (unsigned int k = 0; k < PASO_ROT_Z; k++)
		{
			for (fi = FI_MIN; fi <= FI_MAX; fi+=PASO_ROT_FI )
			{
				normales[pos++] = Matematica::cosHex(fi);
				normales[pos++] = Matematica::sinHex(fi);
				normales[pos++] = 0.0;
			}
		}
	}
	delete bezierCubica;
}

void Canon::displayList() const
{
	glColor3f(1.0, 1.0, 1.0);
	this->luz->setPropiedadesMaterial();
	ODTextura::displayList();
}

void Canon::inicializarLuz()
{
	this->luz = new IluminacionMaterial(1.0, 1.0, 1.0);
}

void Canon::eliminarLuz()
{
	delete this->luz;
}
