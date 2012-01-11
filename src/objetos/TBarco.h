/*
 * TBarco.h
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#ifndef TBARCO_H_
#define TBARCO_H_

#include "ConstantesMundo.h"

#include "barco/ConstantesBarco.h"

#include "../matematica/Matematica.h"
#include "../grafica/FuncOpenGL.h"

class TBarco {
public:
	TBarco();
	void ejecutar() const;
	virtual ~TBarco();
	void incAngulo();
	void getTPto( const float x, const float y, const float z, float &fx, float &fy, float &fz ) const;
	float getAngulo() const;
	float getAlturaBarco() const;

private:
	float angulo;
};

#endif /* TBARCO_H_ */
