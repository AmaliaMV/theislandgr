/*
 * Castillo.cpp
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#include "Castillo.h"

#define FACT_CORRECCION_TORRE_Z (CteCastillo::ALTURA_LADRILLO_TORRE/2.0f) //0.5 /*0.5 factor de correccion*/
#define FACT_CORRECCION_Z (CteCastillo::ALTURA_LADRILLO/2.0f)
Castillo::Castillo( Fisica* fisica, float alturaPiso )
{
	cuerpos = new FPrismaRigido*[CteCastillo::CANT_LADRILLOS];
	textura = new Textura24("texturas/piedra4.bmp");
	this->inicializarLuz();

	unsigned int num = 0;
	this->dibujarTorre(num, fisica, alturaPiso);
	this->dibujarMuros(num, fisica, alturaPiso);
	this->agregarCuerposAlModelo( fisica->getMundoFisico() );
}

Castillo::~Castillo()
{
	for ( unsigned int numLadrillo = 0; numLadrillo < CteCastillo::CANT_LADRILLOS; numLadrillo++ )
		delete cuerpos [numLadrillo];

	delete []cuerpos;
	delete textura;
}

void Castillo::dibujar()
{
	unsigned int numLadrillo = 0;

	this->luz->setPropiedadesMaterial();
	for ( ; numLadrillo < CteCastillo::CANT_LADRILLOS; numLadrillo ++ )
	{
			cuerpos [numLadrillo]->dibujar();
	}
}

void Castillo::agregarCuerposAlModelo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	unsigned int num = 0;
	for ( ; num < CteCastillo::CANT_LADRILLOS; num++ )
		cuerpos [num]->agregarseAlMundo(dynamicsWorld);
}

void Castillo::dibujarTorre( unsigned int &indice, Fisica *fisica, float alturaPiso )
{
	/* creo los collision shape para la torre */
	btBoxShape* shapeX = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO_TORRE/2.0,CteCastillo::ANCHO_LADRILLO_TORRE/2.0,CteCastillo::ALTURA_LADRILLO_TORRE/2.0));
	btBoxShape* shapeY = new  btBoxShape(btVector3(CteCastillo::ANCHO_LADRILLO_TORRE/2.0,CteCastillo::LARGO_LADRILLO_TORRE/2.0,CteCastillo::ALTURA_LADRILLO_TORRE/2.0));

	/* constantes para dibujar la torre */
	int reves = 1;		// esto es para ir poniendo los ladrillos en forma intercalda
	unsigned int num = 0, altura = 0;
	float posX, posY;
	const float longLado = CteCastillo::ANCHO_LADRILLO_TORRE * CteCastillo::CANT_LADRILLOS_LADOS_TORRE + CteCastillo::LARGO_LADRILLO_TORRE + CteCastillo::SEPARACION * CteCastillo::CANT_LADRILLOS_LADOS_TORRE,
			deltaPos = CteCastillo::ANCHO_LADRILLO_TORRE + CteCastillo::SEPARACION,
			posInicialCte = longLado/2.0f - CteCastillo::LARGO_LADRILLO_TORRE/2.0f,
			posInicial = longLado/2.0f - CteCastillo::ANCHO_LADRILLO_TORRE/2.0f,
			deltaZ = CteCastillo::ALTURA_LADRILLO_TORRE,
			longLadoXCastillo = CteCastillo::ANCHO_LADRILLO * CteCastillo::ANCHO_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::ANCHO_CASTILLO,
			desplazY = longLado/2 + longLadoXCastillo/2 + 0.005; //+ CteCastillo::SEPARACION/4; comentado porq salta

	/* creo el constructor de ladrillos*/
	BuildLadrillo *constructor = new BuildLadrillo( longLado, longLado, (CteCastillo::ALTURA_TORRE + 1) * deltaZ );

	/* posiciono los ladrillos de la torre */
	for ( ; altura < CteCastillo::ALTURA_TORRE ; altura++ )
	{
		/* parte x+ */
		posX = posInicialCte;
		posY = -posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

			posY += deltaPos * reves;
		}

		/* parte y+ */
		posX = posInicial  * reves;
		posY = posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

			posX -= deltaPos * reves;
		}

		/* parte x- */
		posX = -posInicialCte;
		posY = posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

			posY -= deltaPos * reves;
		}

		/* parte y- */
		posX = -posInicial * reves;
		posY = -posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

			posX += deltaPos * reves;
		}

		reves *= -1;
	}

	/*dibujo los ladrillos q ser'ian de la parte de arriba "la corona"*/

	//cada dos ladrillos dibujo uno
	const float CADA_DOS_LADRILLOS = 2;
	/* parte x+ */
	posX = posInicialCte;
	posY = -posInicial * reves;
	for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_ARRIBA_TORRE; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
				posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

		posY += deltaPos * reves * CADA_DOS_LADRILLOS ;
	}

	/* parte y+ */
	posX = posInicial  * reves;
	posY = posInicialCte;
	for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_ARRIBA_TORRE; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
				posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

		posX -= deltaPos * reves * CADA_DOS_LADRILLOS ;
	}

	/* parte x- */
	posX = -posInicialCte;
	posY = posInicial * reves;
	for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_ARRIBA_TORRE; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
				posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

		posY -= deltaPos * reves * CADA_DOS_LADRILLOS ;
	}

	/* parte y- */
	posX = -posInicial * reves;
	posY = -posInicialCte;
	for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_ARRIBA_TORRE; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
				posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z, alturaPiso, desplazY );

		posX += deltaPos * reves * CADA_DOS_LADRILLOS ;
	}

	indice+= CteCastillo::CANT_LADRILLOS_TORRE;

	/* agrego los collision shape al mundo */
	fisica->addCollisionShape( shapeX );
	fisica->addCollisionShape( shapeY );

	delete constructor;
}

void Castillo::dibujarMuros( unsigned int &indice, Fisica *fisica, float alturaPiso )
{
	/* ctes para dibujar */
	int reves = 1; // esto es para ir poniendo los ladrillos en forma intercalda
	unsigned int num = 1, altura = 0;
	float posX, posY;
	const float longLadoX = CteCastillo::ANCHO_LADRILLO * CteCastillo::ANCHO_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::ANCHO_CASTILLO,
			longLadoY = CteCastillo::ANCHO_LADRILLO * CteCastillo::PROFUNDIDAD_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::PROFUNDIDAD_CASTILLO,
			deltaPos = CteCastillo::ANCHO_LADRILLO + CteCastillo::SEPARACION,
			posInicialCteX = longLadoY/2.0f - CteCastillo::LARGO_LADRILLO/2.0f,
			posInicialX = longLadoY/2.0f - CteCastillo::ANCHO_LADRILLO/2.0f,
			posInicialCteY = longLadoX/2.0f - CteCastillo::LARGO_LADRILLO/2.0f,
			posInicialY = longLadoX/2.0f - CteCastillo::ANCHO_LADRILLO/2.0f,
			cantLadrillosAntesPuerta = ( CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) / 2 - 1 /*ult ladrillo long variable-> shapeX1*/ ,
			inicioX1 = posInicialY - deltaPos*cantLadrillosAntesPuerta + CteCastillo::ANCHO_LADRILLO/2.0f /*porque las posiciones son relativas al centro de la figura.*/,
			finX1 = CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO/2.0f + CteCastillo::SEPARACION,
			inicioX2 = -posInicialY + deltaPos * (cantLadrillosAntesPuerta + CteCastillo::ANCHO_PUERTA + 1 /*desperdicio, 1 por el lado derecho de la puerta*/ ) + CteCastillo::ANCHO_LADRILLO / 2.0f,
			finX2 = CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO/2.0f + CteCastillo::SEPARACION,
			deltaZ = CteCastillo::ALTURA_LADRILLO;

	/* creo el constructor de ladrillos*/
	BuildLadrillo *constructor = new BuildLadrillo( longLadoX, longLadoY, CteCastillo::ALTURA_CASTILLO* deltaZ );

	/* creo los collision shape para los distintos ladrillos del muro*/
	btBoxShape* shapeX = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO/2.0, CteCastillo::ANCHO_LADRILLO/2.0, CteCastillo::ALTURA_LADRILLO/2.0));
	btBoxShape* shapeY = new  btBoxShape(btVector3(CteCastillo::ANCHO_LADRILLO/2.0, CteCastillo::LARGO_LADRILLO/2.0, CteCastillo::ALTURA_LADRILLO/2.0));
	btBoxShape* shapePuerta = new  btBoxShape(btVector3(CteCastillo::PROFUNDIDAD_PUERTA/2.0, CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO/2.0, CteCastillo::ALTURA_PUERTA * CteCastillo::ALTURA_LADRILLO/2.0));
	btBoxShape* shapeX1 = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO/2.0, ( inicioX1 - finX1) /2.0, CteCastillo::ALTURA_LADRILLO/2.0));
	btBoxShape* shapeX2 = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO/2.0, ( inicioX2 - finX2 )/2.0, CteCastillo::ALTURA_LADRILLO/2.0));

	/* dibujo la puerta */
	cuerpos [indice] = new Puerta( "texturas/puerta01.bmp", "texturas/madera_nogal.bmp", shapePuerta,
				posInicialCteX,
				0.0,
				shapePuerta->getHalfExtentsWithMargin().getZ() + alturaPiso );

	for ( ; altura < CteCastillo::ALTURA_PUERTA; altura++ )
	{
		/* parte x+ */
		posX = posInicialCteX;
		posY = -posInicialY * reves;
		for ( unsigned int lado = 0; lado < cantLadrillosAntesPuerta; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );
			posY += deltaPos * reves;
		}

		posY = - ( inicioX1 + finX1 ) / 2.0f /*para sacar la posicion media*/* reves;

		cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX1,
				posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

		//puerta

		posY = ( inicioX2 + finX2 ) / 2.0f /*para sacar la posicion media*/* reves;

		cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX2,
				posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

		posY = (-posInicialY + deltaPos * (cantLadrillosAntesPuerta + CteCastillo::ANCHO_PUERTA + 2 /*desperdicio, 1 por el lado derecho de la puerta otro 1 por el izquierdo*/ )) * reves;

		for ( unsigned int lado = 0; lado < ( CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) / 2 - 1 /*ult ladrillo long variable*/; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posY += deltaPos * reves;
		}

		/* parte y+ */
		posX = posInicialX  * reves;
		posY = posInicialCteY;
		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posX -= deltaPos * reves;
		}

		/* parte x- */
		posX = -posInicialCteX;
		posY = posInicialY * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posY -= deltaPos * reves;
		}

		/* parte y- */
		posX = -posInicialX * reves;
		posY = -posInicialCteY;
		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posX += deltaPos * reves;
		}

		reves *= -1;
	}

	/*para la ultima fila del techo del castillo*/
	for ( ; altura < CteCastillo::ALTURA_CASTILLO; altura++ )
	{
		/* parte x+ */
		posX = posInicialCteX;
		posY = -posInicialY * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posY += deltaPos * reves;
		}

		/* parte y+ */
		posX = posInicialX  * reves;
		posY = posInicialCteY;
		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posX -= deltaPos * reves;
		}

		/* parte x- */
		posX = -posInicialCteX;
		posY = posInicialY * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posY -= deltaPos * reves;
		}

		/* parte y- */
		posX = -posInicialX * reves;
		posY = -posInicialCteY;
		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

			posX += deltaPos * reves;
		}

		reves *= -1;
	}

	/*corona del castillo*/

	//cada dos ladrillos dibujo uno
	const float CADA_DOS_LADRILLOS = 2;

	/* parte x+ */
	posX = posInicialCteX;
	posY = -posInicialY * reves;
	for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO/2; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
				posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

		posY += deltaPos * reves * CADA_DOS_LADRILLOS;
	}

	/* parte y+ */
	posX = posInicialX  * reves;
	posY = posInicialCteY;
	for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO/2; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
				posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

		posX -= deltaPos * reves * CADA_DOS_LADRILLOS;
	}

	/* parte x- */
	posX = -posInicialCteX;
	posY = posInicialY * reves;
	for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO/2; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
				posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

		posY -= deltaPos * reves * CADA_DOS_LADRILLOS;
	}

	/* parte y- */
	posX = -posInicialX * reves;
	posY = -posInicialCteY;
	for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO/2; lado++ )
	{
		cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
				posX, posY, altura * deltaZ + FACT_CORRECCION_Z, alturaPiso );

		posX += deltaPos * reves * CADA_DOS_LADRILLOS;
	}


	indice+= CteCastillo::CANT_LARILLOS_CASTILLO;

	/* agrego los collision shape al mundo */
	fisica->addCollisionShape( shapeX );
	fisica->addCollisionShape( shapeY );
	fisica->addCollisionShape( shapePuerta );
	fisica->addCollisionShape( shapeX1 );
	fisica->addCollisionShape( shapeX2 );

	delete constructor;
}

#undef FACT_CORRECCION_TORRE_Z

void Castillo::inicializarLuz()
{
	this->luz = new IluminacionMaterial(1.0, 1.0, 1.0);
}

void Castillo::eliminarLuz()
{
	delete luz;
}
