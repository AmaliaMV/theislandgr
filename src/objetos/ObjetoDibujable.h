/*
 * ObjetoDibujable.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef OBJETODIBUJABLE_H_
#define OBJETODIBUJABLE_H_

#include "../grafica/textura/Textura.h"
#include "../grafica/FuncOpenGL.h"

#include "../ConstantesObjeto.h"
using namespace std;

class ObjetoDibujable {
public:
	ObjetoDibujable();
	virtual void dibujar() const;
	virtual ~ObjetoDibujable() = 0;

protected:
	void compilarDisplayList() const;
	virtual void displayList() const= 0;

private:
	GLuint idDisplayList;

};

#endif /* OBJETODIBUJABLE_H_ */
