/*
 * AdminComandos.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef ADMINCOMANDOS_H_
#define ADMINCOMANDOS_H_

#include "Comando.h"
#include "EComando.h"

#include <map>
#include <sstream>
#include <list>
using namespace std;

class AdminComandos {
public:
	AdminComandos();
	void agregarComando( char tecla, Comando* comando );
	void ejecutarComando( char tecla );
	list<string>* getDescripcion() const;
	virtual ~AdminComandos();

private:
	Comando *buscarComando ( char tecla );

	map<char, Comando* > *comandos;
};

#endif /* ADMINCOMANDOS_H_ */
