/*
 * Barco.cpp
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#include "Barco.h"

Barco::Barco():ObjetoDibujable()
{
//	baranda = new Baranda ();
//	mastil = new Palo("texturas/madera_roble.bmp", 35, 0.85, 0.45);




	partesBarco = new Baupres("texturas/pisoBarco.bmp", "baupres.pto", new TBaupres(),
			crearMastilSecundario( -8.0,
			crearMastilSecundario( 8.0,
			crearMastilPpal( new BarcoBasico ( new EstrategiaTransformacion(), "texturas/madera4.bmp",
					"texturas/pisoBarco.bmp" )))));


	this->compilarDisplayList();
}

void Barco::displayList() const
{
	partesBarco->dibujarComponente();
//	glPushMatrix();
//			glRotatef(-45, 1.0, 0.0, 0.0);
//			glScalef(20,20,20);
//	baupres->dibujar();
//	glPopMatrix();
//	glPushMatrix();
//		glTranslatef(0.0, -15.0, 0.0);
//		glRotatef(180, 0.0, 0.0, 1.0);
//		glScalef(0.75,0.75,0.75);
//		vela->dibujar();
//	glPopMatrix();
//	baranda->dibujar();
//	mastil->dibujar();
//
}


Barco::~Barco()
{
//	delete baranda;
//	delete mastil;
//	delete vela;
	delete partesBarco;
	delete baupres;
}

ComponenteBarco* Barco::crearMastilPpal( ComponenteBarco *parteBarco)
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
