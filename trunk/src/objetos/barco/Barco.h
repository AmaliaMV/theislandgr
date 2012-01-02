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

#include "barcoBasico/BarcoBasico.h"



class Barco: public ObjetoDibujable {
public:
	Barco();
	virtual ~Barco();

protected:
	virtual void displayList() const;

private:
	ComponenteBarco *partesBarco;

	Baupres *baupres;
	ComponenteBarco* crearMastilPpal( ComponenteBarco *parteBarco);
	ComponenteBarco* crearMastilSecundario( float desplazamiento, ComponenteBarco *parteBarco );

};

#endif /* BARCO_H_ */
