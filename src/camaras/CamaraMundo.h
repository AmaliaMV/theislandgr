/*
 * CamaraMundo.h
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#ifndef CAMARAMUNDO_H_
#define CAMARAMUNDO_H_

#include "Camara.h"
#include "../matematica/Matematica.h"

#define ANGULO_MAX_TITA 89
class CamaraMundo : public Camara {
public:
	CamaraMundo();
	void setEye();
	void setAt ();
	void alejar();
	void acercar();
	virtual ~CamaraMundo();

private:
	float distancia;
};

#endif /* CAMARAMUNDO_H_ */
