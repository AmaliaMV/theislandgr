/*
 * Barco.cpp
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#include "Barco.h"

const float Barco::ALTO_CAJA = 3.5;
const float Barco::LARGO_CAJA = 3.0;

Barco::Barco(AdministradorArchivo *administrador):ObjetoDibujable()
{
	TCajaCanon *tcaja;

	canon = new Canon( administrador->getNombreArchivo(CANON_TEXTURA), administrador->getNombreArchivo( CANON_PTOS ) );

	partesBarco =
			new CajaCanon ( administrador->getNombreArchivo(CAJA_CANON), ALTO_CAJA, 3.5, LARGO_CAJA, tcaja = new TCajaCanon( ALTO_CAJA, LARGO_CAJA ),
			new BarandaEntera( administrador->getNombreArchivo(BARANDA_BARCO), 5.0, 2 * CteBarco::RADIO_Y, new EstrategiaTransformacion(),
			new Baupres( administrador->getNombreArchivo(BAUPRES_TEXTURA), administrador->getNombreArchivo(BAUPRES_PTOS), new TBaupres(),
			crearMastilSecundario( administrador, -8.0,
			crearMastilSecundario( administrador, 8.0,
			crearPaloMayor( administrador,
					new BarcoBasico ( new EstrategiaTransformacion(), administrador->getNombreArchivo(CASCO_BARCO), administrador->getNombreArchivo(PISO_BARCO))
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

ComponenteBarco* Barco::crearPaloMayor(AdministradorArchivo *administrador, ComponenteBarco *parteBarco)
{
	return 	new Vela ( administrador->getNombreArchivo(TELA_VELA_PRINCIPAL), CteBarco::LARGO_VELA_PPAL, CteBarco::ALTO_VELA_PPAL, 0.08,
				administrador->getNombreArchivo(PALO_VELA), 0.50, new TVelaPrincipal( CteBarco::LARGO_VELA_PPAL/2.0, 20.0 ),
			new Vela ( administrador->getNombreArchivo(TELA_VELA_SECUNDARIA), CteBarco::LARGO_VELA_CHICA_PPAL, CteBarco::ALTO_VELA_CHICA_PPAL, 0.09,
				administrador->getNombreArchivo(PALO_VELA), 0.35, new TVelaPrincipal( CteBarco::LARGO_VELA_CHICA_PPAL/2.0, 35.0 ),
			new Mirador ( administrador->getNombreArchivo(PALO_VELA), administrador->getNombreArchivo(PISO_BARCO), administrador->getNombreArchivo(PALO_VELA), 2.5,
				new TMirador( CteBarco::ALTURA_MIRADOR ),
			new Palo ( administrador->getNombreArchivo(PALO_BARCO), CteBarco::ALTURA_PALO_PPAL, 0.85, 0.45,
				new EstrategiaTransformacion(), parteBarco
			))));
}

ComponenteBarco* Barco::crearMastilSecundario(AdministradorArchivo *administrador, float desplazamiento,  ComponenteBarco *parteBarco)
{
	return 	new Vela ( administrador->getNombreArchivo(TELA_VELA_SECUNDARIA), CteBarco::LARGO_VELA_SEC, CteBarco::ALTO_VELA_SEC, 0.08,
				administrador->getNombreArchivo(PALO_VELA), 0.50, new TVelaSecundaria( CteBarco::LARGO_VELA_SEC/2.0, 18.0, desplazamiento ),
			new Vela ( administrador->getNombreArchivo(TELA_VELA_SECUNDARIA), CteBarco::LARGO_VELA_CHICA_SEC, CteBarco::ALTO_VELA_CHICA_SEC, 0.09,
				administrador->getNombreArchivo(PALO_VELA), 0.35, new TVelaSecundaria( CteBarco::LARGO_VELA_CHICA_SEC/2.0, 31.0, desplazamiento ),
			new Palo ( administrador->getNombreArchivo(PALO_BARCO), CteBarco::ALTURA_PALO_SEC, 0.75, 0.35,
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
