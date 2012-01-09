/*
 * Barco.cpp
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#include "Barco.h"

const float Barco::ALTO_CAJA = 3.5;
const float Barco::LARGO_CAJA = 3.0;

Barco::Barco():ObjetoDibujable()
{
	TCajaCanon *tcaja;

	canon = new Canon( "texturas/aluminio_pulido3.bmp", "canon3.pto" );

	partesBarco =
			new CajaCanon ( "texturas/madera_nogal.bmp", ALTO_CAJA, 3.5, LARGO_CAJA, tcaja = new TCajaCanon( ALTO_CAJA, LARGO_CAJA ),
			new BarandaEntera( "texturas/madera4.bmp", 5.0, 2 * CteBarco::RADIO_Y, new EstrategiaTransformacion(),
			new Baupres("texturas/pisoBarco.bmp", "baupres.pto", new TBaupres(),
			crearMastilSecundario( -8.0,
			crearMastilSecundario( 8.0,
			crearPaloMayor(
					new BarcoBasico ( new EstrategiaTransformacion(), "texturas/madera4.bmp", "texturas/pisoBarco.bmp" )
			))))));

	tCanon = new TCanon ( canon, tcaja );

	this->compilarDisplayList();
}

void Barco::displayList() const
{ partesBarco->dibujarComponente(); }

Barco::~Barco()
{
	delete partesBarco;
	delete canon;
	delete tCanon;
}

ComponenteBarco* Barco::crearPaloMayor( ComponenteBarco *parteBarco)
{
	return 	new Vela ( "texturas/tela_gris.bmp", CteBarco::LARGO_VELA_PPAL, CteBarco::ALTO_VELA_PPAL, 0.08,
				"texturas/madera_baranda.bmp", 0.50, new TVelaPrincipal( CteBarco::LARGO_VELA_PPAL/2.0, 20.0 ),
			new Vela ( "texturas/tela_gris.bmp", CteBarco::LARGO_VELA_CHICA_PPAL, CteBarco::ALTO_VELA_CHICA_PPAL, 0.09,
				"texturas/madera_baranda.bmp", 0.35, new TVelaPrincipal( CteBarco::LARGO_VELA_CHICA_PPAL/2.0, 35.0 ),
			new Mirador ( "texturas/madera_baranda.bmp", "texturas/pisoBarco.bmp", "texturas/madera_baranda.bmp", 2.5,
				new TMirador( CteBarco::ALTURA_MIRADOR ),
			new Palo ( "texturas/madera_roble.bmp", CteBarco::ALTURA_PALO_PPAL, 0.85, 0.45,
				new EstrategiaTransformacion(), parteBarco
			))));
}

ComponenteBarco* Barco::crearMastilSecundario( float desplazamiento,  ComponenteBarco *parteBarco)
{
	return 	new Vela ( "texturas/tela_gris.bmp", CteBarco::LARGO_VELA_SEC, CteBarco::ALTO_VELA_SEC, 0.08,
				"texturas/madera_baranda.bmp", 0.50, new TVelaSecundaria( CteBarco::LARGO_VELA_SEC/2.0, 18.0, desplazamiento ),
			new Vela ( "texturas/tela_gris.bmp", CteBarco::LARGO_VELA_CHICA_SEC, CteBarco::ALTO_VELA_CHICA_SEC, 0.09,
				"texturas/madera_baranda.bmp", 0.35, new TVelaSecundaria( CteBarco::LARGO_VELA_CHICA_SEC/2.0, 31.0, desplazamiento ),
			new Palo ( "texturas/madera_roble.bmp", CteBarco::ALTURA_PALO_SEC, 0.75, 0.35,
				new TMastilSecundario( desplazamiento ), parteBarco
			)));
}

Canon* Barco::getCanon() const
{ return this->canon; }

void Barco::dibujar()
{
	ObjetoDibujable::dibujar();

	glPushMatrix();
			tCanon->ejecutar();
			canon->dibujar();
	glPopMatrix();
}

TCanon* Barco::getTCanon() const
{ return this->tCanon; }
