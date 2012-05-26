/*
 * PanelOpciones.h
 *
 *  Created on: 08/08/2011
 *      Author: amalia
 */

#ifndef PANELOPCIONES_H_
#define PANELOPCIONES_H_

#include <GL/glut.h>
#include <string>
#include "Panel.h"
#include "Dimensiones.h"

using namespace std;

class PanelOpciones : public Panel{
public:
	PanelOpciones();
	virtual void setPanel();
	virtual void dibujarFondo();
	virtual ~PanelOpciones();
};

#endif /* PANELOPCIONES_H_ */
