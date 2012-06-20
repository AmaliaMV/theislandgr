/*
 * Mundo.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef MUNDO_H_
#define MUNDO_H_

#include "Agua.h"
#include "Cielo.h"
#include "TBarco.h"
#include "NodoPalmera.h"
#include "isla/Isla.h"
#include "barco/Barco.h"
#include "castillo/Castillo.h"
#include "bomba/AdminBombas.h"

#include "../fisica/PisoFisico.h"


#define DIRECTORIO_DE_TEXTURAS texturas

using namespace std;
class Mundo {
public:
	/*nombreArchivoNivel es el nombre del archivo que contiene los path
	 * 					 a los otros archivos que se usarn para dibujar
	 * 					 el mundo*/
	Mundo( string nombreArchivoNivel );
	void dibujar(float xEYE, float yEYE);
	void actualizar();
	void reiniciarFisica();
	void pausar();
	bool estaPausado() const;
	TBarco* getTBarco() const;
	Barco* getBarco() const;
	void lanzarBomba();
	virtual ~Mundo();

private:
	void incAnguloBarco();

	Agua *agua;
	Cielo *cielo;
	Isla *isla;
	Palmera *palmera;
	Barco *barco;
	Castillo *castillo;
	TBarco *posBarco;
	AdminBombas *adminBombas;
	PisoFisico* piso;
	Fisica* fisica;

	list<NodoPalmera*>* palmeras;

	bool pausa;
};

#endif /* MUNDO_H_ */
