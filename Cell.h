#ifndef CELL_H_
#define CELL_H_

#include <exception>
#include <memory>
#include <list>

#include "CoordinateTypes.h"

class HitResult;
class Ship;

/* Objects of this class represent the basic cell component */
class Cell {
public:

	/* constructor, takes the cell's coordinate in the gameboard as parameter */
	Cell(CoordinateType coord) :
		coord_(coord) {
	}

	/* returns a list of hit results, one for each ship attached to this ship */
	std::list<HitResult*> hitMe() const;

	/* attach a ship to this cell 
	 * returns true if attaching succeded false if not */
	bool attachShip(Ship* ship);

	bool isAttached(Ship* ship);

	/* detach a ship form this cell */
	void detachShip(Ship* ship);

	/* get list of Ships that are attached to this cell */
	std::list<Ship*> getAttachedShips() const;

	virtual ~Cell() {
	}
	;
private:
	/* On a cell you can place any number of underwater ships 
	 * but just one that is above water 
         * (you can't have 2 ships above water placed one on each other).
	 * Also checks if the client tryes to attach same ship to the same cell twice
	 * true if the ship can be attached false if not */
	bool isPlaceble(Ship* ship);

	/* the cell's coordinates in the gameboard */
	CoordinateType coord_;

	/* list of ships attached to this cell */
	std::list<Ship*> ships_;

};

#endif
