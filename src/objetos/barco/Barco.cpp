/*
 * Barco.cpp
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#include "Barco.h"

const float Barco::ANG_CANON_MAX = 20.0;
const float Barco::ANG_CANON_MIN = -20.0;
const float Barco::DELTA_ANG = 2.0; //encuenta disminuye o aumenta el ang cada vez q se inc o dec el angulo

const float Barco::ALTO_CAJA = 3.5;
const float Barco::LARGO_CAJA = 3.0;

Barco::Barco():ObjetoDibujable()
{
	this->anguloCanon = 0.0;

	canon = new Canon( "texturas/aluminio_pulido3.bmp", "canon3.pto" );

	partesBarco =
			new CajaCanon ( "texturas/madera_nogal.bmp", ALTO_CAJA, 3.5, LARGO_CAJA, tCajaCanon = new TCajaCanon( ALTO_CAJA, LARGO_CAJA ),
			new BarandaEntera( "texturas/madera4.bmp", 5.0, 2 * CteBarco::RADIO_Y, new EstrategiaTransformacion(),
			new Baupres("texturas/pisoBarco.bmp", "baupres.pto", new TBaupres(),
			crearMastilSecundario( -8.0,
			crearMastilSecundario( 8.0,
			crearPaloMayor(
					new BarcoBasico ( new EstrategiaTransformacion(), "texturas/madera4.bmp", "texturas/pisoBarco.bmp" )
			))))));


	this->compilarDisplayList();
}

void Barco::displayList() const
{
	partesBarco->dibujarComponente();
//	glPushMatrix();
//		glRotatef(-90, 0.0, 1.0, 0.0);
//		prisma->dibujar();
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
	delete partesBarco;
	delete canon;
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

void Barco::incAngulo()
{
	if ( anguloCanon < ANG_CANON_MAX )
		anguloCanon+= DELTA_ANG;
}
void Barco::decAngulo()
{
	if ( anguloCanon > ANG_CANON_MIN )
		anguloCanon-= DELTA_ANG;
}

void Barco::dibujar()
{
	ObjetoDibujable::dibujar();


//
	glPushMatrix();
			tCajaCanon->ejecutar();
			glRotatef(-90.0 + this->anguloCanon , 0.0, 1.0, 0.0);
			glScalef(7, 7, 10);
			glTranslatef(0.0, 0.0, 0.05);
			canon->dibujar();
	glPopMatrix();


}
