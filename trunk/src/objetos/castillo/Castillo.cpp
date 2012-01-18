/*
 * Castillo.cpp
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#include "Castillo.h"

#define FACT_CORRECCION_Z 0.5 /*0.5 factor de correccion*/
Castillo::Castillo( Fisica* fisica )
{
	ladrillos = new Ladrillo*[CteCastillo::CANT_LADRILLOS];
	cout<<"castillo; "<< CteCastillo::CANT_LADRILLOS;
	unsigned int num = 0;
	this->dibujarTorre(num, fisica);
//	this->dibujarMuros(num, fisica);
	this->agregarLadrillosAlModelo( fisica->getMundoFisico() );
}

Castillo::~Castillo()
{
	for ( unsigned int numLadrillo = 0; numLadrillo < CteCastillo::CANT_LADRILLOS; numLadrillo++ )
		delete ladrillos [numLadrillo];

	delete []ladrillos;

}

void Castillo::dibujar()
{
	for ( unsigned int numLadrillo = 0; numLadrillo < CteCastillo::CANT_LADRILLOS; numLadrillo ++ )
		ladrillos [numLadrillo]->dibujar();
}

void Castillo::agregarLadrillosAlModelo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	unsigned int num = 0;
	for ( ; num < CteCastillo::CANT_LADRILLOS; num++ )
		ladrillos [num]->agregarseAlMundo(dynamicsWorld);
}

void Castillo::dibujarTorre( unsigned int &indice, Fisica *fisica )
{
	/* creo los collision shape para la torre */
	btBoxShape* shapeX = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO_TORRE/2.0,CteCastillo::ANCHO_LADRILLO_TORRE/2.0,CteCastillo::ALTURA_LADRILLO_TORRE/2.0));
	btBoxShape* shapeY = new  btBoxShape(btVector3(CteCastillo::ANCHO_LADRILLO_TORRE/2.0,CteCastillo::LARGO_LADRILLO_TORRE/2.0,CteCastillo::ALTURA_LADRILLO_TORRE/2.0));

	/* dibujo la torre */
	int reves = 1;/* esto es para ir poniendo los ladrillos en forma intercalda*/
	unsigned int num = 0, altura = 0;
	float posX, posY;
	const float longLado = CteCastillo::ANCHO_LADRILLO_TORRE * CteCastillo::CANT_LADRILLOS_LADOS_TORRE + CteCastillo::LARGO_LADRILLO_TORRE + CteCastillo::SEPARACION * CteCastillo::CANT_LADRILLOS_LADOS_TORRE,
			deltaPos = CteCastillo::ANCHO_LADRILLO_TORRE + CteCastillo::SEPARACION,
			posInicialCte = longLado/2.0f - CteCastillo::LARGO_LADRILLO_TORRE/2.0f,
			posInicial = longLado/2.0f - CteCastillo::ANCHO_LADRILLO_TORRE/2.0f;

	for ( ; num < CteCastillo::CANT_LADRILLOS_TORRE; altura++ )
	{
		/* parte x+ */
		posX = posInicialCte;
		posY = -posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [indice + num++] = new Ladrillo( "texturas/tex2.bmp", shapeX,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
			posY += deltaPos * reves;
		}

		/* parte y+ */
		posX = posInicial  * reves;
		posY = posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [indice + num++] = new Ladrillo( "texturas/madera4.bmp", shapeY,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
			posX -= deltaPos * reves;
		}

		/* parte x- */
		posX = -posInicialCte;
		posY = posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [indice + num++] = new Ladrillo( "texturas/arena.bmp", shapeX,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
			posY -= deltaPos * reves;
		}

		/* parte y- */
		posX = -posInicial * reves;
		posY = -posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [indice + num++] = new Ladrillo( "texturas/tela_gris.bmp", shapeY,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
			posX += deltaPos * reves;
		}

		reves *= -1;
	}
	indice+= CteCastillo::CANT_LADRILLOS_TORRE;

	/* agrego los collision shape al mundo */
	fisica->addCollisionShape( shapeX );
	fisica->addCollisionShape( shapeY );

}

void Castillo::dibujarMuros( unsigned int &indice, Fisica *fisica )
{
//
//	int reves = 1;/* esto es para ir poniendo los ladrillos en forma intercalda*/
//	unsigned int num = 1, altura = 0;
//	float posX, posY;
//	const float longLadoX = CteCastillo::ANCHO_LADRILLO * CteCastillo::ANCHO_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::ANCHO_CASTILLO,
//			longLadoY = CteCastillo::ANCHO_LADRILLO * CteCastillo::PROFUNDIDAD_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::PROFUNDIDAD_CASTILLO,
//			deltaPos = CteCastillo::ANCHO_LADRILLO + CteCastillo::SEPARACION,
//			posInicialCteX = longLadoY/2.0f - CteCastillo::LARGO_LADRILLO/2.0f,
//			posInicialX = longLadoY/2.0f - CteCastillo::ANCHO_LADRILLO/2.0f,
//			posInicialCteY = longLadoX/2.0f - CteCastillo::LARGO_LADRILLO/2.0f,
//			posInicialY = longLadoX/2.0f - CteCastillo::ANCHO_LADRILLO/2.0f;
////			mitadLongLadoXPuerta = (CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) * CteCastillo::ANCHO_LADRILLO / 2.0f + CteCastillo::SEPARACION * 2 /*L | L | x, x = puerta o L*/;
//
//	/*puerta deberia tener mas masa*/
//	ladrillos [indice] = new Ladrillo( "texturas/madera_nogal.bmp",
//				CteCastillo::ALTURA_PUERTA * CteCastillo::ALTURA_LADRILLO, CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO, CteCastillo::PROFUNDIDAD_PUERTA,
//				posInicialCteX,
//				0.0,
//				FACT_CORRECCION_Z );
//
//	for ( ; num < CteCastillo::CANT_LARILLOS_CASTILLO; altura++ )
//	{
//		/* parte x+ */
//		posX = posInicialCteX;
//		posY = -posInicialY * reves;
//		for ( unsigned int lado = 0; lado < ( CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) / 2 - 1 /*ult ladrillo long variable*/; lado++ )
//		{
//			ladrillos [indice + num++] = new Ladrillo( "texturas/tex2.bmp",
//						CteCastillo::ALTURA_LADRILLO, CteCastillo::ANCHO_LADRILLO, CteCastillo::LARGO_LADRILLO,
//						posX,
//						posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY += deltaPos * reves;
//		}
//
//		ladrillos [indice + num++] = new Ladrillo( "texturas/tex2.bmp",
//					CteCastillo::ALTURA_LADRILLO, - posY * reves, CteCastillo::LARGO_LADRILLO,
//					posX,
//					posY,
//					altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//
//		//puerta
//
//		posY += deltaPos * reves * CteCastillo::ANCHO_PUERTA * 2;
//
//		ladrillos [indice + num++] = new Ladrillo( "texturas/tex2.bmp",
//					CteCastillo::ALTURA_LADRILLO, posY - CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO / 2, CteCastillo::LARGO_LADRILLO,
//					posX,
//					posY,
//					altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//
//
//		for ( unsigned int lado = 0; lado < ( CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) / 2 - 1 /*ult ladrillo long variable*/; lado++ )
//		{
//			ladrillos [indice + num++] = new Ladrillo( "texturas/tex2.bmp",
//						CteCastillo::ALTURA_LADRILLO, CteCastillo::ANCHO_LADRILLO, CteCastillo::LARGO_LADRILLO,
//						posX,
//						posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY += deltaPos * reves;
//		}
//
//
//		/* parte y+ */
//		posX = posInicialX  * reves;
//		posY = posInicialCteY;
//		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
//		{
//			ladrillos [indice + num++] = new Ladrillo( "texturas/madera4.bmp",
//						CteCastillo::ALTURA_LADRILLO, CteCastillo::LARGO_LADRILLO, CteCastillo::ANCHO_LADRILLO,
//						posX,
//						posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posX -= deltaPos * reves;
//		}
//
//		/* parte x- */
//		posX = -posInicialCteX;
//		posY = posInicialY * reves;
//		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
//		{
//			ladrillos [indice + num++] = new Ladrillo( "texturas/arena.bmp",
//						CteCastillo::ALTURA_LADRILLO, CteCastillo::ANCHO_LADRILLO, CteCastillo::LARGO_LADRILLO,
//						posX,
//						posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY -= deltaPos * reves;
//		}
//
//		/* parte y- */
//		posX = -posInicialX * reves;
//		posY = -posInicialCteY;
//		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
//		{
//			ladrillos [indice + num++] = new Ladrillo( "texturas/tela_gris.bmp",
//						CteCastillo::ALTURA_LADRILLO, CteCastillo::LARGO_LADRILLO, CteCastillo::ANCHO_LADRILLO,
//						posX,
//						posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posX += deltaPos * reves;
//		}
//
//		reves *= -1;
//	}
//	indice+= CteCastillo::CANT_LARILLOS_CASTILLO;
//	cout<<"num: "<<num<<endl;
}

#undef FACT_CORRECCION_Z
