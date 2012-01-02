/*
 * Claves.h
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#ifndef CLAVES_H_
#define CLAVES_H_

#include "../../ClavesValidas.h"

#include <list>
using namespace std;

class Claves {
public:
	Claves();
	bool existeLaClave (const string clave) const;
	virtual ~Claves();

private:
	void agregarClave ( const string clave );
	void cargarClaves ();
	list<string> *claves;
};

#endif /* CLAVES_H_ */
