/*
 * Vela.h
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#ifndef VELA_H_
#define VELA_H_

#include "../DecoradorBarco.h"

#include "../../ODTextura.h"
#include "../../geometricos/CilindroConTextura.h"

#include "../../../grafica/iluminacion/IluminacionMaterial.h"

#include "TelaVela.h"

class Vela: public ObjetoDibujable, public DecoradorBarco {
public:
	Vela( string nombreTextVela, float largo, float alto, float factCurvatura,
			string nombreTextPalo, float radio,
			EstrategiaTransformacion* transformacion, ComponenteBarco* aDecorar );
	virtual ~Vela();

protected:
	void dibujar();

private:
	void displayList() const;

	TelaVela *tela;
	CilindroConTextura *palito;

	float LARGO;
	float ALTO;

	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* VELA_H_ */
