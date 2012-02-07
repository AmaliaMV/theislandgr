/*
 * Panel.h
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#ifndef PANEL_H_
#define PANEL_H_

#include <string.h>
#include <GL/glut.h>
#include "TamanoPantalla.h"

class Panel {
public:
	Panel();
	virtual void dibujar();
	virtual ~Panel() {}

protected:
	virtual void setPanel();
	virtual void setProyeccion() const;
	virtual void dibujarFondo() = 0;
	void escribir( const char *texto);
	void setEscalaReferencia( GLdouble XMIN, GLdouble XMAX, GLdouble YMIN, GLdouble YMAX);
	void setDimensiones ( GLint topX, GLint topY, GLsizei ancho, GLsizei alto );

private:
	GLint topX;
	GLint topY;
	GLsizei ancho;
	GLsizei alto;

	GLdouble XMIN;
	GLdouble XMAX;
	GLdouble YMIN;
	GLdouble YMAX;
};

#endif /* PANEL_H_ */
