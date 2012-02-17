/*
 * VerMenuComandos.cpp
 *
 *  Created on: 16/02/2012
 *      Author: amalia
 */

#include "VerMenuComandos.h"

VerMenuComandos::VerMenuComandos(MCmdJuegos* menuComando, Mundo* mundo):Comando()
{
	this->menuComandos = menuComando;
	this->mundo = mundo;
}

void VerMenuComandos::ejecutar()
{
	menuComandos->modificarMostrar();
	if ( menuComandos->seVe() == true && mundo->estaPausado() == false)
		mundo->pausar();
	else if ( menuComandos->seVe() == false && mundo->estaPausado() == true)
		mundo->pausar();
}

const string VerMenuComandos::getDescripcion() const
{
	return "Ver menu de comandos";
}

VerMenuComandos::~VerMenuComandos() {}
