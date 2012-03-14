/*
 * Baupres.h
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#ifndef BAUPRES_H_
#define BAUPRES_H_

#include "../../ODTextura.h"
#include "../DecoradorBarco.h"
#include "../../../grafica/textura/Textura24.h"
#include "../../../grafica/iluminacion/IluminacionMaterial.h"
#include "../../../matematica/curva/CalculadoraBezier.h"
#include "../../../matematica/Matematica.h"
#include "../../../archivos/adminArchPtosCrtl/ArchivoPtosControl.h"

class Baupres: public ODTextura, public DecoradorBarco {
public:
	Baupres( string nombreText, string nombreArchPtos,
			EstrategiaTransformacion *transformacion, ComponenteBarco *aDecorar );
	virtual ~Baupres();

protected:
	void dibujar();

private:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void generarNormales();

	PuntosControl *ptosCtrl;

	float ALTURA;
	float RADIO_SUPERIOR;
	float RADIO_INFERIOR;

	static const unsigned int GRADO_BEZIER = 3;
	static const unsigned int PASO_ROT_Z = 10;
	static const unsigned int PASO_ROT_FI = 10;
	static const unsigned int PASO_BAR = 15;
	static const unsigned int FI_MAX = 360;
	static const unsigned int FI_MIN = 0;

	void inicializarLuz();
	void eliminarLuz();
	IluminacionMaterial* luz;
};

#endif /* BAUPRES_H_ */
