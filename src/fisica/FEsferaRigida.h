/*
 * EsferaRigida.h
 *
 *  Created on: 28/01/2012
 *      Author: amalia
 */

#ifndef FESFERARIGIDA_H_
#define FESFERARIGIDA_H_

#include "../grafica/FuncOpenGL.h"

#include "Fisica.h"

class FEsferaRigida {
public:
	FEsferaRigida( btSphereShape* shape, float posX, float posY, float posZ, float masa );
	void actualizar();
	void agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld );
	virtual void dibujar() const = 0;
	virtual ~FEsferaRigida();

protected:
	void aplicarTransformada() const;

private:
	void initPosicion( float posX, float posY, float posZ );
	void initVelocidad();

	btRigidBody* cuerpo;

	float* POSICION_INICIAL;
	float* VELOCIDAD_INICIAL;

	float tiempo;

	static const float GRAVEDAD;
	static const float DELTA_TIEMPO;
};

#endif /* ESFERARIGIDA_H_ */
