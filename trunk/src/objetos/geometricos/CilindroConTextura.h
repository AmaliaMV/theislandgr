/*
 * CilindroConTextura.h
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#ifndef CILINDROCONTEXTURA_H_
#define CILINDROCONTEXTURA_H_

#include "LadoCilindroConTextura.h"
#include "CirculoConTextura.h"

class CilindroConTextura: public ObjetoDibujable {
public:
	CilindroConTextura( string nombreTextura, float radio, float altura );
	virtual ~CilindroConTextura();

protected:
	virtual void displayList() const;

private:
	LadoCilindroConTextura* lado;
	CirculoConTextura* tapa;

	static const unsigned int PASO = 30;
};

#endif /* CILINDROCONTEXTURA_H_ */
