/*
 * Castillo.cpp
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#include "Castillo.h"

#define FACT_CORRECCION_Z 0.5 /*0.5 factor de correccion*/
Castillo::Castillo( btDiscreteDynamicsWorld* dynamicsWorld  )
{
	ladrillos = new Ladrillo*[CteCastillo::CANT_LADRILLOS];
	int reves = 1;/* esto es para ir poniendo los ladrillos en forma intercalda*/
	unsigned int num = 0, altura = 0;
	float posX, posY;
	const float longLado = CteCastillo::ANCHO_LADRILLO_TORRE * CteCastillo::CANT_LADRILLOS_LADOS_TORRE + CteCastillo::LARGO_LADRILLO_TORRE + CteCastillo::SEPARACION * CteCastillo::CANT_LADRILLOS_LADOS_TORRE,
			deltaPos = CteCastillo::ANCHO_LADRILLO_TORRE + CteCastillo::SEPARACION,
			posInicialCte = longLado/2.0f - CteCastillo::LARGO_LADRILLO_TORRE/2.0f,
			posInicial = longLado/2.0f - CteCastillo::ANCHO_LADRILLO_TORRE/2.0f;

	cout<<" longLado = "<< longLado<<endl;
	for ( ; num < CteCastillo::CANT_LADRILLOS_TORRE; altura++ )
	{
		/* parte x+ */
		posX = posInicialCte;
		posY = -posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [num++] = new Ladrillo( "texturas/tex2.bmp",
						CteCastillo::ALTURA_LADRILLO_TORRE, CteCastillo::ANCHO_LADRILLO_TORRE, CteCastillo::LARGO_LADRILLO_TORRE,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			cout<<" 1) posX = "<< posX<<" posY= "<<posY<<endl;
			posY += deltaPos * reves;
		}

		/* parte y+ */
		posX = posInicial  * reves;
		posY = posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [num++] = new Ladrillo( "texturas/madera4.bmp",
						CteCastillo::ALTURA_LADRILLO_TORRE, CteCastillo::LARGO_LADRILLO_TORRE, CteCastillo::ANCHO_LADRILLO_TORRE,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			cout<<" 2) posX = "<< posX<<" posY= "<<posY<<endl;
			posX -= deltaPos * reves;
		}

		/* parte x- */
		posX = -posInicialCte;
		posY = posInicial * reves;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [num++] = new Ladrillo( "texturas/arena.bmp",
						CteCastillo::ALTURA_LADRILLO_TORRE, CteCastillo::ANCHO_LADRILLO_TORRE, CteCastillo::LARGO_LADRILLO_TORRE,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			cout<<" 3) posX = "<< posX<<" posY= "<<posY<<endl;
			posY -= deltaPos * reves;
		}

		/* parte y- */
		posX = -posInicial * reves;
		posY = -posInicialCte;
		for ( unsigned int lado = 0; lado < CteCastillo::CANT_LADRILLOS_LADOS_TORRE; lado++ )
		{
			ladrillos [num++] = new Ladrillo( "texturas/tela_gris.bmp",
						CteCastillo::ALTURA_LADRILLO_TORRE, CteCastillo::LARGO_LADRILLO_TORRE, CteCastillo::ANCHO_LADRILLO_TORRE,
						posX,
						posY,
						altura * (CteCastillo::ALTURA_LADRILLO_TORRE + CteCastillo::SEPARACION) + FACT_CORRECCION_Z );
//			cout<<" 4) posX = "<< posX<<" posY= "<<posY<<endl;
			posX += deltaPos * reves;
		}

		reves *= -1;
	}

	num = 0;
	for ( ; num < CteCastillo::CANT_LADRILLOS; num++ )
		ladrillos [num]->agregarseAlMundo(dynamicsWorld);

//	bool sacarLadrillo = 0;
//	unsigned int num = 0, numLadrillo = 0, cantLadrillosFila;
//	float posX, posY, largoParedEnFloat;
//	const float deltaPos = CteCastillo::ANCHO_LADRILLO + CteCastillo::SEPARACION;
//
//	cout<<"cant ladrillos supuestos: "<<CteCastillo::CANT_LADRILLOS<<endl;
////	cout<<CteCastillo::ANCHO_CASTILLO * CteCastillo::ALTURA_CASTILLO/2<<endl;
////	cout<<(CteCastillo::ANCHO_CASTILLO-1) * CteCastillo::ALTURA_CASTILLO/2 <<endl;
////	cout << CteCastillo::ANCHO_CASTILLO * (CteCastillo::ALTURA_CASTILLO % 2)<<endl;
//	for ( unsigned int alto = 0; alto < CteCastillo::ALTURA_CASTILLO; alto ++ )
//	{
//		posX = (CteCastillo::ANCHO_CASTILLO * CteCastillo::ANCHO_LADRILLO + ( CteCastillo::PROFUNDIDAD_CASTILLO - 1 ) * CteCastillo::SEPARACION) / 2.0f - CteCastillo::ANCHO_LADRILLO/2.0f;
//
//		cantLadrillosFila = CteCastillo::ANCHO_CASTILLO - sacarLadrillo;
//		largoParedEnFloat = cantLadrillosFila * CteCastillo::ANCHO_LADRILLO + (cantLadrillosFila-1) * CteCastillo::SEPARACION;
//		posY = - (largoParedEnFloat/2.0) + (float)(CteCastillo::ANCHO_LADRILLO/2.0);
//
//		for ( numLadrillo = 0; numLadrillo < cantLadrillosFila; numLadrillo ++, num++ )
//		{
//			/*ladrillos de adelante*/
//			ladrillos [num] = new Ladrillo( "texturas/piedra4.bmp",
//					CteCastillo::ALTURA_LADRILLO, CteCastillo::ANCHO_LADRILLO, CteCastillo::LARGO_LADRILLO,
//					posX,
//					posY,
//					alto * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION)+FACT_CORRECCION_Z );
//			ladrillos [num]->agregarseAlMundo(dynamicsWorld);
//			cout<<" x= "<< posX <<
//				  " y= "<< posY <<
//				  " z= "<< alto * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION)+FACT_CORRECCION_Z <<endl;
//			posY += deltaPos;
//		}
//
////
////
////			/*ladrillos de atras*/
////			ladrillos [numLadrillo] = new Ladrillo( "texturas/piedra4.bmp",
////								CteCastillo::ALTURA_LADRILLO, CteCastillo::ANCHO_LADRILLO, CteCastillo::LARGO_LADRILLO,
////								-(float)((CteCastillo::PROFUNDIDAD_CASTILLO * CteCastillo::ANCHO_LADRILLO)/ 2.0 - CteCastillo::SEPARACION ),
////								ancho * (CteCastillo::ANCHO_LADRILLO + CteCastillo::SEPARACION) - posY * (CteCastillo::ANCHO_LADRILLO / 2 + CteCastillo::SEPARACION ) ,
////								alto * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION)+FACT_CORRECCION_Z );
////			ladrillos [numLadrillo]->agregarseAlMundo(dynamicsWorld);
////			numLadrillo++;
////		}
//
////		posY = (CteCastillo::PROFUNDIDAD_CASTILLO * CteCastillo::ANCHO_LADRILLO + (CteCastillo::PROFUNDIDAD_CASTILLO - 1 ) * CteCastillo::SEPARACION )/ 2.0f - CteCastillo::ANCHO_LADRILLO/2.0f;
////		cantLadrillosFila = CteCastillo::PROFUNDIDAD_CASTILLO - (1-sacarLadrillo);
////		largoParedEnFloat = (float)(cantLadrillosFila * CteCastillo::ANCHO_LADRILLO) + (float)((cantLadrillosFila-1) * CteCastillo::SEPARACION);
////		posX = - (largoParedEnFloat/2.0) + (float)(CteCastillo::ANCHO_LADRILLO/2.0);
////		for ( numLadrillo = 0 ; numLadrillo < cantLadrillosFila; numLadrillo ++, num++ )
////		{
////			/*ladrillos del costado y+*/
////			ladrillos [num] = new Ladrillo( "texturas/piedra4.bmp",
////								CteCastillo::ALTURA_LADRILLO, CteCastillo::LARGO_LADRILLO, CteCastillo::ANCHO_LADRILLO,
////								posX,
////								posY,
////								alto * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z);
////			ladrillos [num]->agregarseAlMundo(dynamicsWorld);
////
////			cout<<" x= "<< posX <<
////				  " y= "<< (float)(CteCastillo::ANCHO_CASTILLO *  CteCastillo::ANCHO_LADRILLO / 2) <<
////				  " z= "<< alto * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) + FACT_CORRECCION_Z <<endl;
////			posX += deltaPos;
////		}
//
////			/*ladrillos del costado y-*/
////			ladrillos [numLadrillo] = new Ladrillo( "texturas/piedra4.bmp",
////								CteCastillo::ALTURA_LADRILLO, CteCastillo::LARGO_LADRILLO, CteCastillo::ANCHO_LADRILLO,
////								ancho * (CteCastillo::ANCHO_LADRILLO + CteCastillo::SEPARACION) - posY * (CteCastillo::ANCHO_LADRILLO / 2 + CteCastillo::SEPARACION ) ,
////								- (float)(CteCastillo::ANCHO_CASTILLO * CteCastillo::ANCHO_LADRILLO / 2),
////								alto * (CteCastillo::ALTURA_LADRILLO + CteCastillo::SEPARACION) );
////			ladrillos [numLadrillo]->agregarseAlMundo(dynamicsWorld);
////			numLadrillo++;
////		}
//
//
//
//		sacarLadrillo = !sacarLadrillo;
//	}
	cout<<"cant ladrillos de verdad: "<<num<<endl;

//		// defino la posicion inicial de la caja
//		float posX= 0.0;//((col-cantCols/2)*(tamanioCaja+separacion));
//		float posY= 0.0;//(row-cantRows/2)*(tamanioCaja+separacion);
//		float posZ= 0.0;//altura*(tamanioCaja+separacion);

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

//#undef CANT_LADRILLOS
//#undef ALTURA_CASTILLO
//#undef PROFUNDIDAD_CASTILLO
//#undef ALTURA_LADRILLO
//#undef ANCHO_LADRILLO
//#undef LARGO_LADRILLO
#undef FACT_CORRECCION_Z
