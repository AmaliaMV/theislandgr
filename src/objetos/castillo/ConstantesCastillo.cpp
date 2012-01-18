/*
 * ConstantesCastillo.cpp
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#include "ConstantesCastillo.h"

CteCastillo::CteCastillo() {}
CteCastillo::~CteCastillo() {}

/*por si altura es impar uso el %*/
#define CANT_LADRILLOS_ADELANTE_X 	ANCHO_CASTILLO * (ALTURA_CASTILLO/2) + (ANCHO_CASTILLO-1) * (ALTURA_CASTILLO/2) + ANCHO_CASTILLO * (ALTURA_CASTILLO % 2)
#define CANT_LADRILLOS_ATRAS_X 		ANCHO_CASTILLO * (ALTURA_CASTILLO/2) + (ANCHO_CASTILLO-1) * (ALTURA_CASTILLO/2) + ANCHO_CASTILLO * (ALTURA_CASTILLO % 2)
#define CANT_LADRILLOS_LADO_YPOS	(PROFUNDIDAD_CASTILLO - 1) * (ALTURA_CASTILLO/2) + PROFUNDIDAD_CASTILLO * (ALTURA_CASTILLO/2) + (PROFUNDIDAD_CASTILLO-1) * (ALTURA_CASTILLO % 2)
#define CANT_LADRILLOS_LADO_YNEG    (PROFUNDIDAD_CASTILLO - 1) * (ALTURA_CASTILLO/2) + PROFUNDIDAD_CASTILLO * (ALTURA_CASTILLO/2) + (PROFUNDIDAD_CASTILLO-1) * (ALTURA_CASTILLO % 2)

const float CteCastillo::SEPARACION = 0.05;
const unsigned int CteCastillo::CANT_LADRILLOS = /*CANT_LARILLOS_CASTILLO;// + */CANT_LADRILLOS_TORRE;// /*CANT_LADRILLOS_ADELANTE_X + */CANT_LADRILLOS_ATRAS_X ;//+ CANT_LADRILLOS_LADO_YPOS ;//+ CANT_LADRILLOS_LADO_YNEG;

// para el castillo
const unsigned int CteCastillo::ALTURA_CASTILLO = 4;//2;//8;
const unsigned int CteCastillo::PROFUNDIDAD_CASTILLO = 3;//5;//2;//4;
const unsigned int CteCastillo::ANCHO_CASTILLO = 6;//5;
const float CteCastillo::ALTURA_LADRILLO = 1.0;
const float CteCastillo::ANCHO_LADRILLO = 2.0;//3.0;
const float CteCastillo::LARGO_LADRILLO = 1.0;
const unsigned int CteCastillo::CANT_LARILLOS_CASTILLO = (ANCHO_CASTILLO * 2 + PROFUNDIDAD_CASTILLO * 2) * ALTURA_CASTILLO - ANCHO_PUERTA * ALTURA_PUERTA /*saco ladrillos de mas por la puerta*/+1 /*la puerta*/;

// para la torre
const unsigned int CteCastillo::ALTURA_TORRE = 10;
const unsigned int CteCastillo::CANT_LADRILLOS_LADOS_TORRE = 2;
const unsigned int CteCastillo::CANT_LADOS_TORRE = 4;
const unsigned int CteCastillo::CANT_LADRILLOS_TORRE = CANT_LADOS_TORRE * CANT_LADRILLOS_LADOS_TORRE * ALTURA_TORRE ;
const float CteCastillo::ALTURA_LADRILLO_TORRE = 1.0;
const float CteCastillo::ANCHO_LADRILLO_TORRE = 2.0;
const float CteCastillo::LARGO_LADRILLO_TORRE = 1.0;

// para la puerta
const unsigned int CteCastillo::ANCHO_PUERTA = 2;
const unsigned int CteCastillo::ALTURA_PUERTA = (ALTURA_CASTILLO - 1);
const float CteCastillo::PROFUNDIDAD_PUERTA = LARGO_LADRILLO / 2.0f;

#undef CANT_LADRILLOS_ADELANTE_X
#undef CANT_LADRILLOS_ATRAS_X
#undef CANT_LADRILLOS_LADO_YPOS
