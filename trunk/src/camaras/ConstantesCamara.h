/*
 * ConstantesCamara.h
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#ifndef CONSTANTESCAMARA_H_
#define CONSTANTESCAMARA_H_

#include "../objetos/ConstantesMundo.h"
class CteCamara {
public:
	virtual ~CteCamara();

	static const float ANGULO_MAX_VERTICAL;
	static const float POS_X_EYE_CAM_CASTILLO;
	static const float POS_Y_EYE_CAM_CASTILLO;
	static const float POS_Z_EYE_CAM_CASTILLO;

private:
	CteCamara();
};

#endif /* CONSTANTESCAMARA_H_ */
