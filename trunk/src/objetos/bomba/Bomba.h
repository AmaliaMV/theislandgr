/*
 * Bomba.h
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#ifndef BOMBA_H_
#define BOMBA_H_

#include "../../grafica/iluminacion/IluminacionMaterial.h"
#include "../../fisica/FEsferaRigida.h"

class Bomba: public FEsferaRigida {
public:
	Bomba( btSphereShape* shape, const float posX, const float posY, const float posZ , const float angHCanon, const float angVCanon, const float angBarco, const float radioDistancia );
	void dibujar() const;
	virtual ~Bomba();

private:
	static const float MASA_BOMBA;
	float RADIO;

	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* BOMBA_H_ */
