/*
 * PanelTitulo.h
 *
 *  Created on: 08/08/2011
 *      Author: amalia
 */

#ifndef PANELTITULO_H_
#define PANELTITULO_H_

#include <GL/glut.h>
#include <string>
#include "Panel.h"
#include "Dimensiones.h"

using namespace std;

class PanelTitulo : public Panel {
public:
	PanelTitulo();
	virtual void setPanel();
	virtual void dibujarFondo();
	void fondoNombreArchivo();
	void borrarNombreArch();
	void setNombreArch(string nombre);
	virtual ~PanelTitulo();
private:
	string nombreArch;
};

#endif /* PANELTITULO_H_ */
