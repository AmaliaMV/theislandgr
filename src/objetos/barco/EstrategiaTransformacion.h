/*
 * EstrategiaTransformacion.h
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#ifndef ESTRATEGIATRANSFORMACION_H_
#define ESTRATEGIATRANSFORMACION_H_

//vale la pena q sea Singleton?
/*
 * comportamiento por default: no aplica ninguna transformacion
 */
#include "../../grafica/FuncOpenGL.h"

class EstrategiaTransformacion {
public:
	EstrategiaTransformacion();
	virtual void ejecutar();
	virtual ~EstrategiaTransformacion();
};

#endif /* ESTRATEGIATRANSFORMACION_H_ */
