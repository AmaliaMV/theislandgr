/*
 * BuildLadrillo.h
 *
 *  Created on: 27/01/2012
 *      Author: amalia
 *
 *
 *      resumen de fatores:
 *
 *      4 --- 3
 *      |     |
 *      1 --- 2
 *
 * 							 t		longParedX		longParedY
 *
 * 	x=cte x > 0			1    1        1/2              0
 *  y=cte y > 0			2   -1        1                1/2
 * 	x=cte x < 0 		3	-1        3/2              1
 * 	y=cte y < 0			4    1        2                3/2
 */

#ifndef BUILDLADRILLO_H_
#define BUILDLADRILLO_H_

#include "Ladrillo.h"

class BuildLadrillo {
public:
	BuildLadrillo( float longParedX, float longParedY, float longParedZ );
	virtual ~BuildLadrillo();

	Ladrillo* construirLadrilloParedFrente( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ, float desplaZ = 0, float desplaY=0 );
	Ladrillo* construirLadrilloParedCostado( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ, float desplaZ = 0,  float desplaY=0 );

private:
	float longParedX;
	float longParedY;
	float longParedZ;

	float getCoordTextH ( float t, int factorT, float factorLongX, float factorLongY );
	float getCoordTextV ( float t );
};

#endif /* BUILDLADRILLO_H_ */
