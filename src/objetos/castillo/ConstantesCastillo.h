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
	static const unsigned int CANT_LARILLOS_CASTILLO;
	static const float ALTURA_LADRILLO;
	static const float ANCHO_LADRILLO;
	static const float LARGO_LADRILLO;
	static const unsigned int CANT_LADRILLOS_TORRE;
	static const float ALTURA_LADRILLO_TORRE;
	static const float ANCHO_LADRILLO_TORRE;
	static const float LARGO_LADRILLO_TORRE;
	static const unsigned int CANT_LADRILLOS_LADOS_TORRE;
	static const unsigned int CANT_LADOS_TORRE;
	static const unsigned int ALTURA_TORRE;
	static const unsigned int ANCHO_PUERTA;
	static const unsigned int ALTURA_PUERTA;
	static const float PROFUNDIDAD_PUERTA;

	virtual ~CteCastillo();

private:
	CteCastillo();
};

#endif /* CONSTANTESCASTILLO_H_ */
