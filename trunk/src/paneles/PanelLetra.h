/*
 * PanelLetra.h
 *
 *  Created on: 08/08/2011
 *      Author: amalia
 */

#ifndef PANELLETRA_H_
#define PANELLETRA_H_

#include <GL/glut.h>
#include <string>
#include "Panel.h"
#include "Dimensiones.h"
using namespace std;

class PanelLetra : public Panel {
public:
	PanelLetra();
	virtual void setPanel();
	virtual void dibujarFondo();
	virtual ~PanelLetra();
};

#endif /* PANELLETRA_H_ */
