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

#include "barcoBasico/BarcoBasico.h"

#include "baranda/BarandaEntera.h"

#include "mastil/Palo.h"
#include "mastil/Vela.h"
#include "mastil/Baupres.h"
#include "mirador/Mirador.h"

#include "canon/Canon.h"
#include "canon/CajaCanon.h"

#include "TCanon.h"
#include "TBaupres.h"
#include "TMirador.h"
#include "TCajaCanon.h"
#include "TVelaPrincipal.h"
#include "TVelaSecundaria.h"
#include "TMastilSecundario.h"

#include "../geometricos/PrismaConTextura.h"

class Barco: public ObjetoDibujable {
public:
	Barco();
	void dibujar();
	virtual ~Barco();
	void incAngulo();
	void decAngulo();
	TCanon* getPosCanon() const;

protected:
	virtual void displayList() const;

private:
	TCanon *tCanon;
	ComponenteBarco *partesBarco;

	Canon *canon;
	LadoPrismaConTextura *prisma;
	ComponenteBarco* crearPaloMayor( ComponenteBarco *parteBarco);
	ComponenteBarco* crearMastilSecundario( float desplazamiento, ComponenteBarco *parteBarco );

	static const float ALTO_CAJA;
	static const float LARGO_CAJA;
};

#endif /* BARCO_H_ */
