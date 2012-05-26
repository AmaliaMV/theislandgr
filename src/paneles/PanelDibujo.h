/*
 * PanelDibujo.h
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#ifndef PANELDIBUJO_H_
#define PANELDIBUJO_H_

#include <GL/glut.h>
#include "Panel.h"
#include "Dimensiones.h"


class PanelDibujo: public Panel {
public:
	PanelDibujo();
	virtual void setPanel();
	virtual void dibujarFondo();
	virtual ~PanelDibujo();
};

#endif /* PANELDIBUJO_H_ */
