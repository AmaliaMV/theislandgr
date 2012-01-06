/*
 * Canon.h
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#ifndef CANON_H_
#define CANON_H_

#include "../../ODTextura.h"
#include "../DecoradorBarco.h"
#include "../../../matematica/Matematica.h"
#include "../../../matematica/curva/CalculadoraBezier.h"
#include "../../../grafica/textura/Textura24.h"
#include "../../../archivos/adminArchPtosCrtl/ArchivoPtosControl.h"

class Canon: public ODTextura {
public:
	Canon( string nombreText, string nombreArchPtos );
	virtual ~Canon();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

private:

	PuntosControl *ptosCtrl;

	static const unsigned int GRADO_BEZIER = 3;
	static const unsigned int PASO_ROT_Z = 10;
	static const unsigned int PASO_ROT_FI = 10;
	static const unsigned int PASO_BAR = 15;
	static const unsigned int FI_MAX = 360;
	static const unsigned int FI_MIN = 0;
};

#endif /* CANON_H_ */
