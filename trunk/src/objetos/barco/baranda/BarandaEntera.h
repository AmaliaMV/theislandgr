/*
 * BarandaEntera.h
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#ifndef BARANDAENTERA_H_
#define BARANDAENTERA_H_

#include "../../../grafica/textura/Textura24.h"
#include "../../../grafica/iluminacion/IluminacionMaterial.h"
#include "../../ObjetoDibujable.h"

#include "../DecoradorBarco.h"

#include "ParteAbajo.h"
#include "ParteArriba.h"

class BarandaEntera: public ObjetoDibujable, public DecoradorBarco {
public:
	BarandaEntera( string nombreTextura, float altura, float longitud,
			EstrategiaTransformacion* estrategia, ComponenteBarco* aDecorar );
	virtual ~BarandaEntera();

protected:
	void dibujar();

private:

	void displayList() const;

	Textura24* textura;

	ParteArriba *arriba;
	ParteAbajo *abajo;
	ParteArriba *arribaAdentro; //solo para la iluminacion
	ParteAbajo *abajoAdentro;


	float ALTURA;
	float LONGITUD;

	static const int INICIO = -175;
	static const int FIN = 175;

	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* BARANDAENTERA_H_ */
