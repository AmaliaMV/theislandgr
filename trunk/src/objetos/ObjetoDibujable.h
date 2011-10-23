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
	ObjetoDibujable( Textura *textura ); /* Textura = del objeto */
	virtual void dibujar();
	virtual ~ObjetoDibujable();

protected:
	const Textura* getTextura() const;
	GLuint getIdDisplayList() const ;

private:
	Textura *textura;
	GLuint idDisplayList;

};

#endif /* OBJETODIBUJABLE_H_ */
