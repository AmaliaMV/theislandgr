/*
 * PisoDeBarco.h
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#ifndef PISODEBARCO_H_
#define PISODEBARCO_H_

#include "../ConstantesBarco.h"

#include "../../ODTextura.h"

#include "../../../grafica/textura/Textura24.h"
#include "../../../grafica/iluminacion/IluminacionMaterial.h"
#include "../../../matematica/Matematica.h"

class PisoDeBarco: public ODTextura {
public:
	PisoDeBarco( const string nombreTextura );
	virtual ~PisoDeBarco();

protected:
	void displayList() const;

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	static const unsigned int cantPasosTita;

	/*para la iluminacion*/
	IluminacionMaterial* luz;
	void inicializarLuces();
	void eliminarLuces();
};

#endif /* PISODEBARCO_H_ */
