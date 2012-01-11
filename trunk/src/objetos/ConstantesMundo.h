/*
 * ConstanteMundo.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#ifndef CONSTANTESMUNDO_H_
#define CONSTANTESMUNDO_H_

class CteMundo {
public:
	virtual ~CteMundo();

	static const float NIVEL_AGUA;
	static const float RADIO_NAVEGACION;
	static const float DELTA_ANGULO_BARCO;
	static const float RADIO_MUNDO;

private:
	CteMundo();

};

#endif /* CONSTANTESMUNDO_H_ */
