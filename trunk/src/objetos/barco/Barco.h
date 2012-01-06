/*
 * Barco.h
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#ifndef BARCO_H_
#define BARCO_H_

#include "../ObjetoDibujable.h"

#include "../../grafica/textura/Textura24.h"
#include "../../matematica/Matematica.h"

#include "mastil/Palo.h"
#include "mastil/Vela.h"
#include "mastil/TVelaPrincipal.h"
#include "mastil/TMastilSecundario.h"
#include "mastil/TVelaSecundaria.h"
#include "mastil/Baupres.h"
#include "mastil/TBaupres.h"
#include "mirador/Mirador.h"
#include "mirador/TMirador.h"

#include "canon/Canon.h"
#include "canon/CajaCanon.h"
#include "canon/TCajaCanon.h"

#include "barcoBasico/BarcoBasico.h"

#include "baranda/BarandaEntera.h"

#include "../geometricos/PrismaConTextura.h"

class Barco: public ObjetoDibujable {
public:
	Barco();
	void dibujar();
	virtual ~Barco();
	void incAngulo();
	void decAngulo();

protected:
	virtual void displayList() const;

private:
	TCajaCanon *tCajaCanon;
	ComponenteBarco *partesBarco;

	Canon *canon;
	LadoPrismaConTextura *prisma;
	ComponenteBarco* crearPaloMayor( ComponenteBarco *parteBarco);
	ComponenteBarco* crearMastilSecundario( float desplazamiento, ComponenteBarco *parteBarco );

	float anguloCanon;

	static const float ANG_CANON_MAX;
	static const float ANG_CANON_MIN;
	static const float DELTA_ANG;

	static const float ALTO_CAJA;
	static const float LARGO_CAJA;
};

#endif /* BARCO_H_ */
