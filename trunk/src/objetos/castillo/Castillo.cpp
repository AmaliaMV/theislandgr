/*
 * Castillo.cpp
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#include "Castillo.h"

#define FACT_CORRECCION_TORRE_Z (CteCastillo::ALTURA_LADRILLO_TORRE/2.0f) //0.5 /*0.5 factor de correccion*/
#define FACT_CORRECCION_Z (CteCastillo::ALTURA_LADRILLO/2.0f)
Castillo::Castillo( Fisica* fisica )
{
	cuerpos = new CuerpoFisicoRigido*[CteCastillo::CANT_LADRILLOS];
	textura = new Textura24("texturas/piedra4.bmp");//*/Textura24("texturas/a.bmp");
	cout<<"castillo "<< CteCastillo::CANT_LADRILLOS<<endl;
	unsigned int num = 0;
	this->dibujarTorre(num, fisica, textura);
//	this->dibujarMuros(num, fisica, textura);
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
	for ( unsigned int numLadrillo = 0; numLadrillo < CteCastillo::CANT_LADRILLOS; numLadrillo ++ )
		cuerpos [numLadrillo]->dibujar();
}

void Castillo::agregarCuerposAlModelo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	unsigned int num = 0;
	for ( ; num < CteCastillo::CANT_LADRILLOS; num++ )
		cuerpos [num]->agregarseAlMundo(dynamicsWorld);
}

void Castillo::dibujarTorre( unsigned int &indice, Fisica *fisica, Textura* textura)
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
			deltaZ = CteCastillo::ALTURA_LADRILLO_TORRE; //+ CteCastillo::SEPARACION/4; comentado porq salta

	/* creo el constructor de ladrillos*/
//	BuildLadrillo *constructor = new BuildLadrillo( CteCastillo::ANCHO_LADRILLO_TORRE * CteCastillo::CANT_LADRILLOS_LADOS_TORRE + CteCastillo::LARGO_LADRILLO_TORRE, CteCastillo::ANCHO_LADRILLO_TORRE * CteCastillo::CANT_LADRILLOS_LADOS_TORRE + CteCastillo::LARGO_LADRILLO_TORRE, CteCastillo::ALTURA_TORRE * CteCastillo::ALTURA_LADRILLO_TORRE );
	BuildLadrillo *constructor = new BuildLadrillo( longLado, longLado, CteCastillo::ALTURA_TORRE * CteCastillo::ALTURA_LADRILLO_TORRE );
	for ( ; num < CteCastillo::CANT_LADRILLOS_TORRE; altura++ )
	{
		/* parte x+ */
		posX = posInicialCte;
		posY = -posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z );

			posY += deltaPos * reves;
		}

		/* parte y+ */
		posX = posInicial  * reves;
		posY = posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z);

			posX -= deltaPos * reves;
		}

		/* parte x- */
		posX = -posInicialCte;
		posY = posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedFrente( textura, shapeX,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z);

			posY -= deltaPos * reves;
		}

		/* parte y- */
		posX = -posInicial * reves;
		posY = -posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			cuerpos [indice + num++] = constructor->construirLadrilloParedCostado( textura, shapeY,
					posX, posY, altura * deltaZ + FACT_CORRECCION_TORRE_Z );

			posX += deltaPos * reves;
		}

		reves *= -1;

		cout<<"sig fila"<<endl;
	}

	indice+= CteCastillo::CANT_LADRILLOS_TORRE;

	/* agrego los collision shape al mundo */
	fisica->addCollisionShape( shapeX );
	fisica->addCollisionShape( shapeY );
}

void Castillo::dibujarMuros( unsigned int &indice, Fisica *fisica, Textura* textura )
{
//	/* ctes para dibujar */
//	int reves = 1; // esto es para ir poniendo los ladrillos en forma intercalda
//	unsigned int num = 1, altura = 0;
//	float posX, posY;
//	const float longLadoX = CteCastillo::ANCHO_LADRILLO * CteCastillo::ANCHO_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::ANCHO_CASTILLO,
//			longLadoY = CteCastillo::ANCHO_LADRILLO * CteCastillo::PROFUNDIDAD_CASTILLO + CteCastillo::LARGO_LADRILLO + CteCastillo::SEPARACION * CteCastillo::PROFUNDIDAD_CASTILLO,
//			deltaPos = CteCastillo::ANCHO_LADRILLO + CteCastillo::SEPARACION,
//			posInicialCteX = longLadoY/2.0f - CteCastillo::LARGO_LADRILLO/2.0f,
//			posInicialX = longLadoY/2.0f - CteCastillo::ANCHO_LADRILLO/2.0f,
//			posInicialCteY = longLadoX/2.0f - CteCastillo::LARGO_LADRILLO/2.0f,
//			posInicialY = longLadoX/2.0f - CteCastillo::ANCHO_LADRILLO/2.0f,
//			cantLadrillosAntesPuerta = ( CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) / 2 - 1 /*ult ladrillo long variable-> shapeX1*/ ,
//			inicioX1 = posInicialY - deltaPos*cantLadrillosAntesPuerta + CteCastillo::ANCHO_LADRILLO/2.0f /*porque las posiciones son relativas al centro de la figura.*/,
//			finX1 = CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO/2.0f + CteCastillo::SEPARACION,
//			inicioX2 = -posInicialY + deltaPos * (cantLadrillosAntesPuerta + CteCastillo::ANCHO_PUERTA + 1 /*desperdicio, 1 por el lado derecho de la puerta*/ ) + CteCastillo::ANCHO_LADRILLO / 2.0f,
//			finX2 = CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO/2.0f + CteCastillo::SEPARACION;
//
//	/* para la textura */
////	float inicio_textH, inicio_textV = 0.0;
////	const float long_textH = CteCastillo::ANCHO_LADRILLO_TORRE * CteCastillo::CANT_LADRILLOS_LADOS_TORRE,
////			long_textV = CteCastillo::ALTURA_TORRE * CteCastillo::ALTURA_LADRILLO_TORRE ;
//
//	/* creo los collision shape para la torre */
//	btBoxShape* shapeX = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO/2.0, CteCastillo::ANCHO_LADRILLO/2.0, CteCastillo::ALTURA_LADRILLO/2.0));
//	btBoxShape* shapeY = new  btBoxShape(btVector3(CteCastillo::ANCHO_LADRILLO/2.0, CteCastillo::LARGO_LADRILLO/2.0, CteCastillo::ALTURA_LADRILLO/2.0));
//	btBoxShape* shapePuerta = new  btBoxShape(btVector3(CteCastillo::PROFUNDIDAD_PUERTA/2.0, CteCastillo::ANCHO_PUERTA * CteCastillo::ANCHO_LADRILLO/2.0, CteCastillo::ALTURA_PUERTA * CteCastillo::ALTURA_LADRILLO/2.0));
//	btBoxShape* shapeX1 = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO/2.0, ( inicioX1 - finX1) /2.0, CteCastillo::ALTURA_LADRILLO/2.0));
//	btBoxShape* shapeX2 = new  btBoxShape(btVector3(CteCastillo::LARGO_LADRILLO/2.0, ( inicioX2 - finX2 )/2.0, CteCastillo::ALTURA_LADRILLO/2.0));
//
//cout<<"tam ladri 1: "<<inicioX1 - finX1<<endl;
//cout<<"tam ladri 2: "<<inicioX2 - finX2<<endl;
//
//cout<<"posicion inicial: "<< posInicialY<<endl;
//cout<<"delta posicionY : "<< deltaPos<<endl;
//
///* dibujo la puerta */
//	/*puerta deberia tener mas masa*/
//	cuerpos [indice] = new Puerta( "texturas/puerta01.bmp", "texturas/madera_nogal.bmp", shapePuerta,
//				posInicialCteX,
//				0.0,
//				shapePuerta->getHalfExtentsWithMargin().getZ() );
//
//	for ( ; altura < CteCastillo::ALTURA_PUERTA; altura++ )
//	{
//		/* parte x+ */
//		posX = posInicialCteX;
//		posY = -posInicialY * reves;
//		for ( unsigned int lado = 0; lado < cantLadrillosAntesPuerta; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeX, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z
//						);
//			posY += deltaPos * reves; cout<<"cant ladrillos x+ "<<num-1<<endl;
//		}
//cout<<"pos antes puerta: "<<posY<<endl;
//		posY = - ( inicioX1 + finX1 ) / 2.0f /*para sacar la posicion media*/* reves;
//cout<<"pos antes puerta: "<<posY<<endl;
//		cuerpos [indice + num++] = new Ladrillo( textura, shapeX1, posX, posY,
//					altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//
//		//puerta
//
//		posY = ( inicioX2 + finX2 ) / 2.0f /*para sacar la posicion media*/* reves;
//cout<<"pos despues puerta: "<<posY<<endl;
//		cuerpos [indice + num++] = new Ladrillo( textura, shapeX2, posX, posY,
//					altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//		posY = (-posInicialY + deltaPos * (cantLadrillosAntesPuerta + CteCastillo::ANCHO_PUERTA + 2 /*desperdicio, 1 por el lado derecho de la puerta otro 1 por el izquierdo*/ )) * reves;
//cout<<"pos despues puerta: "<<posY<<endl;
//		for ( unsigned int lado = 0; lado < ( CteCastillo::ANCHO_CASTILLO - CteCastillo::ANCHO_PUERTA) / 2 - 1 /*ult ladrillo long variable*/; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeX, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY += deltaPos * reves; cout<<"cant ladrillos x+ (continuacion)"<<num-1<<endl;
//		}
//
//
//		/* parte y+ */
//		posX = posInicialX  * reves;
//		posY = posInicialCteY;
//		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeY, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posX -= deltaPos * reves; cout<<"cant ladrillos y+ "<<num-1<<endl;
//		}
//
//		/* parte x- */
//		posX = -posInicialCteX;
//		posY = posInicialY * reves;
//		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeX, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY -= deltaPos * reves; cout<<"cant ladrillos x- "<<num-1<<endl;
//		}
//
//		/* parte y- */
//		posX = -posInicialX * reves;
//		posY = -posInicialCteY;
//		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeY, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posX += deltaPos * reves; cout<<"cant ladrillos y+ "<<num-1<<endl;
//		}
//
//		reves *= -1;
//
//	cout<<"....num por ahora: "<<num<<endl;
//	}
//
//	/*para la ultima fila del techo del castillo*/
//
//		/* parte x+ */
//		posX = posInicialCteX;
//		posY = -posInicialY * reves;
//		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeX, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY += deltaPos * reves; cout<<"cant ladrillos x+ "<<num-1<<endl;
//		}
//
//		/* parte y+ */
//		posX = posInicialX  * reves;
//		posY = posInicialCteY;
//		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeY, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posX -= deltaPos * reves; cout<<"cant ladrillos y+ "<<num-1<<endl;
//		}
//
//		/* parte x- */
//		posX = -posInicialCteX;
//		posY = posInicialY * reves;
//		for ( unsigned int lado = 0; lado < CteCastillo::ANCHO_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeX, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posY -= deltaPos * reves; cout<<"cant ladrillos x- "<<num-1<<endl;
//		}
//
//		/* parte y- */
//		posX = -posInicialX * reves;
//		posY = -posInicialCteY;
//		for ( unsigned int lado = 0; lado < CteCastillo::PROFUNDIDAD_CASTILLO; lado++ )
//		{
//			cuerpos [indice + num++] = new Ladrillo( textura, shapeY, posX, posY,
//						altura * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			posX += deltaPos * reves; cout<<"cant ladrillos y+ "<<num-1<<endl;
//		}
//	indice+= CteCastillo::CANT_LARILLOS_CASTILLO;
//
//	/* agrego los collision shape al mundo */
//	fisica->addCollisionShape( shapeX );
//	fisica->addCollisionShape( shapeY );
//	fisica->addCollisionShape( shapePuerta );
//
//	cout<<"num: "<<num<<endl;
}

#undef FACT_CORRECCION_TORRE_Z
