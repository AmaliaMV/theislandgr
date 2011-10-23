/*
 * Coord2DMouse.h
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#ifndef COORD2DMOUSE_H_
#define COORD2DMOUSE_H_

class Coord2DMouse {
public:
	Coord2DMouse();
	Coord2DMouse ( int xMouse, int yMouse );
	void setxMouse( int x );
	void setyMouse( int y );
	int getxMouse () const;
	int getyMouse () const;
	virtual ~Coord2DMouse();

private:
	int x;
	int y;
};

#endif /* COORD2DMOUSE_H_ */
