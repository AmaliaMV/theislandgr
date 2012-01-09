/*
 * ConstantesBarco.h
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#ifndef CONSTANTESBARCO_H_
#define CONSTANTESBARCO_H_

class CteBarco
{
public:
	/* ancho y largo del casco del barco */
	static const float RADIO_X;
	static const float RADIO_Y;
	/* altura del casco del barco */
	static const float RADIO_Z;

	/* angulo q barro en forma horizontal */
	static const float TITA_MIN;
	static const float TITA_MAX;
	/* angulo q barro en forma vertical */
	static const float FI_MIN;
	static const float FI_MAX;
	/* angulo max para la baranda*/
	static const float FI_MAX_BARANDA;

	/*Para la vela principal*/
	static const float LARGO_VELA_PPAL;
	static const float ALTO_VELA_PPAL;
	static const float LARGO_VELA_CHICA_PPAL;
	static const float ALTO_VELA_CHICA_PPAL;

	/* mirador */
	static const float ALTURA_MIRADOR;
	static const float ALTURA_PALO_PPAL;

	/*Para la vela secundaria*/
	static const float LARGO_VELA_SEC;
	static const float ALTO_VELA_SEC;
	static const float LARGO_VELA_CHICA_SEC;
	static const float ALTO_VELA_CHICA_SEC;
	static const float ALTURA_PALO_SEC;

};

#endif /* CONSTANTESBARCO_H_ */
