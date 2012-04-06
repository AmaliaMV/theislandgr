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
#include "../../../grafica/iluminacion/IluminacionMaterial.h"
#include "../../../archivos/adminArchPtosCrtl/ArchivoPtosControl.h"

class Canon: public ODTextura {
public:
	Canon( string nombreText, string nombreArchPtos );
	float getAngV() const;
	float getAngH() const;
	void incAngV();
	void decAngV();
	void derecha();
	void izquierda();
	virtual ~Canon();

protected:
	void displayList() const;
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void generarNormales();

private:

	PuntosControl *ptosCtrl;

	static const unsigned int GRADO_BEZIER = 3;
	static const unsigned int PASO_ROT_Z = 10;
	static const unsigned int PASO_ROT_FI = 10;
	static const unsigned int PASO_BAR = 15;
	static const unsigned int FI_MAX = 360;
	static const unsigned int FI_MIN = 0;

	float angV;
	float angH;

	static const float ANGH_CANON_MAX;
	static const float ANGH_CANON_MIN;
	static const float ANGV_CANON_MAX;
	static const float ANGV_CANON_MIN;
	static const float DELTA_ANG;

	/*iluminacion*/
	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* CANON_H_ */
