/*
 * EsferaRigida.h
 *
 *  Created on: 28/01/2012
 *      Author: amalia
 */

#ifndef FESFERARIGIDA_H_
#define FESFERARIGIDA_H_

#include "../grafica/FuncOpenGL.h"
#include "../matematica/Matematica.h"

#include "Fisica.h"

class FEsferaRigida {
public:
	FEsferaRigida( btSphereShape* shape, const float posX, const float posY, const float posZ, const float masa, const float angH, const float angV, const float angBarco, const float radio );
	void actualizar();
	void agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld );
	virtual void dibujar() const = 0;
	virtual ~FEsferaRigida();

protected:
	void aplicarTransformada() const;

private:
	void initPosicion( const float posX, const float posY, const float posZ );
	void initVelocidad( const float angHCanon, const float angVCanon, const float angBarco, const float radio );

	btRigidBody* cuerpo;

	float* POSICION_INICIAL;
	float* VELOCIDAD_INICIAL;

	float tiempo;

	static const float GRAVEDAD;
	static const float DELTA_TIEMPO;
	static const float MODULO_VEL0;
};

#endif /* ESFERARIGIDA_H_ */
