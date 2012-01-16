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
const unsigned int CteCastillo::ALTURA_CASTILLO = 2;//8;
const unsigned int CteCastillo::PROFUNDIDAD_CASTILLO = 5;//2;//4;
const unsigned int CteCastillo::ANCHO_CASTILLO = 2;//5;
const unsigned int CteCastillo::CANT_LADRILLOS = /*CANT_LADRILLOS_ADELANTE_X + */CANT_LADRILLOS_ATRAS_X + CANT_LADRILLOS_LADO_YPOS ;//+ CANT_LADRILLOS_LADO_YNEG;
const float CteCastillo::ALTURA_LADRILLO = 1.0;
const float CteCastillo::ANCHO_LADRILLO = 3.0;//1.0;//3.0;
const float CteCastillo::LARGO_LADRILLO = 1.0;
//const float CteCastillo::ANCHO_CASTILLO_F = ANCHO_CASTILLO * ANCHO_LADRILLO + (ANCHO_CASTILLO - 1) * SEPARACION;
/*   ANCHO_CASTILLO * ANCHO_LADRILLO + (ANCHO_CASTILLO - 1) * SEPARACION => unidad = float
 *		/--------------------/
 *
 * 		|--|--|--|--|--|--|--|
 *
 */

#undef CANT_LADRILLOS_ADELANTE_X
#undef CANT_LADRILLOS_ATRAS_X
#undef CANT_LADRILLOS_LADO_YPOS
