/*
 * AdministradorArchivo.h
 *
 *  Created on: 02/08/2011
 *      Author: amalia
 */

#ifndef ADMINISTRADORARCHIVO_H_
#define ADMINISTRADORARCHIVO_H_

#include <fstream>
#include <map>
#include <utility>

#include "../EArchivoInexistente.h"
#include "Claves.h"

using namespace std;

typedef pair<string, string> componente;

class AdministradorArchivo {
public:
	AdministradorArchivo( const string nomArchAdmin );
	string getNombreArchivo ( const string clave ) const;
	virtual ~AdministradorArchivo();

private:
	ifstream archivo;
	map<string, string> *mapaDeArchivos;

	void abrirArchivo( string nomArchAdmin );
	void testExisteArchivo ( string nombreArchivo );
	void cerrarArchivo ();
	void cargarLosArchivos();
	bool llegoAlfinalDelArchivo();
};

#endif /* ADMINISTRADORARCHIVO_H_ */
