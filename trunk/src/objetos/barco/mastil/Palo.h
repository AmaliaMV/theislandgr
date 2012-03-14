/*
 * Palo.h
 *
 *  Created on: 28/11/2011
 *      Author: amalia
 */

#ifndef PALO_H_
#define PALO_H_

#include "../DecoradorBarco.h"

#include "../../ODTextura.h"

#include "../../../grafica/textura/Textura24.h"
#include "../../../grafica/iluminacion/IluminacionMaterial.h"

class Palo: public ODTextura, public DecoradorBarco {
public:
	Palo( string nombreTextura, float altura, float radioSuperior, float radioInferior,
			EstrategiaTransformacion* transformacion, ComponenteBarco* aDecorar );
	virtual ~Palo();

protected:
	void dibujar();

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void generarNormales();

	float ALTURA;
	float RADIO_SUPERIOR;
	float RADIO_INFERIOR;

	static const unsigned int PASO = 30;

	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* PALO_H_ */
