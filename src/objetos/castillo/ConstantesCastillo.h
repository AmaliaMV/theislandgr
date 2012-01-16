/*
 * ConstantesCastillo.h
 *
 *  Created on: 15/01/2012
 *      Author: amalia
 */

#ifndef CONSTANTESCASTILLO_H_
#define CONSTANTESCASTILLO_H_

class CteCastillo {
public:

	static const float SEPARACION;
	static const unsigned int ALTURA_CASTILLO; 			// unidad = cant de ladrillos
	static const unsigned int PROFUNDIDAD_CASTILLO;		// unidad = cant de ladrillos
	static const unsigned int ANCHO_CASTILLO; 			// unidad = cant de ladrillos
	static const unsigned int CANT_LADRILLOS;
	static const float ALTURA_LADRILLO;
	static const float ANCHO_LADRILLO;
	static const float LARGO_LADRILLO;

	virtual ~CteCastillo();

private:
	CteCastillo();
};

#endif /* CONSTANTESCASTILLO_H_ */
