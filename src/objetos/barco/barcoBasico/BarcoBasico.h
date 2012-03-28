/*
 * BarcoBasico.h
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#ifndef BARCOBASICO_H_
#define BARCOBASICO_H_

#include "CascoDeBarco.h"
#include "PisoDeBarco.h"

#include "../ComponenteBarco.h"

#include "../../ObjetoDibujable.h"

class BarcoBasico: public ComponenteBarco, public ObjetoDibujable {
public:
	BarcoBasico( EstrategiaTransformacion *transformacion, string texturaCasco, string texturaPiso );
	virtual ~BarcoBasico();

protected:
	void displayList() const;
	void dibujar();

private:
	CascoDeBarco *casco;
	PisoDeBarco *piso;

	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* BARCOBASICO_H_ */
