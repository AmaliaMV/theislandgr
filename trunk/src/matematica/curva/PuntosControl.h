/*
 * PuntosControl.h
 *
 *  Created on: 25/05/2011
 *      Author: Amalia
 */

#ifndef PUNTOSCONTROL_H_
#define PUNTOSCONTROL_H_

#include <iostream>

#include "../../ConstantesObjeto.h"
#include "../Matematica.h"
#include "ECurvas.h"

using namespace std;

#define MAX_PTO_CTRL 40
#define PRECISION 100000.0

class PuntosControl {
public:
	PuntosControl();

	PuntosControl( const PuntosControl &ptos );

	void agregarPto(float v[]); /* los punto de control tienen CteObjeto::CANT_COORD_PTO coordenadas*/
	void sacarUltPto();
	float* getPtos() const;

	/*
	 * hay que liberar el punto que retorna la funcion cuando se
	 * deje de utilizar
	 */
	float* getPto( unsigned int pto ) const;

	unsigned int getCantPtos() const;

	virtual ~PuntosControl();

	/* trasformas las coordenas del mouse, en coordenas del cuadro en donde se
	 * dibujan los puntos y devuelve el pto
	 *
	 * 		ptos: referencia a PuntosControl donde se va a agregar el punto
	 * 		xMouse: coordenada x del mouse
	 * 		yMouse: coordenada y del mouse
	 * 		xBorde: coordenada x de donde empieza el borde de la ventana
	 * 		yBorde: coordenada y de donde empieza el borde de la ventana
	 * 		ancho: ancho de la ventan en donde se va a dibujar el pto
	 * 		alto: alto de la ventan en donde se va a dibujar el pto
	 * */
	static void definirPto(float pto [], const int xMouse, const int yMouse, const int xBorde, const int yBorde, const int ancho, const int alto);

private:

	float *ptos;
	unsigned int cantPto;
};

#endif /* PUNTOSCONTROL_H_ */
