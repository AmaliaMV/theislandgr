/*
 * AdminComandos.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "AdminComandos.h"

AdminComandos::AdminComandos()
{
	comandos = new map<char, Comando*>();
}

void AdminComandos::agregarComando( char tecla, Comando* comando )
{
	if ( this->buscarComando( tecla ) != NULL )
	{
		throw new EComando ("Ya se encuentra en uso la tecla: " + tecla );
	}

	comandos->insert(pair<char, Comando*>(tecla, comando));
}

void AdminComandos::ejecutarComando( char tecla )
{
	Comando* comando = this->buscarComando( tecla );

	if ( comando != NULL )
		comando->ejecutar();
}

list<string>* AdminComandos::getDescripcion() const
{
	list<string>* lista = new list<string>;
	map<char, Comando* >::iterator it = comandos->begin();

	for (;it != comandos->end(); it++)
	{
		string descripcion = "";
		descripcion += (*it).first;
		descripcion.append( " - " + (*it).second->getDescripcion());

		lista->push_back( descripcion );
	}

	return lista;
}


Comando* AdminComandos::buscarComando ( char tecla )
{
	map<char, Comando* >::iterator it = comandos->begin();

	it = comandos->find(tecla);

	if ( it != comandos->end() )
		return (*it).second;

	return NULL;
}

AdminComandos::~AdminComandos()
{
	map<char, Comando* >::iterator it = comandos->begin();

	for( ; it != comandos->end() ; it++ )
	 	 delete (*it).second;

	delete comandos;
}
