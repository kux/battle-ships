
#ifndef CELL_H_
#define CELL_H_

#include <exception>
#include <memory>
#include <list>

#include "CoordinateTypes.h"

//forward declarations of needed classes
class HitResult;
class Ship;


//objects of this class represent the basic cell component
class Cell
{
public:

	//constructor, takes the cell's coordinate in the gameboard as parameter
	Cell( CoordinateType coord): coord_(coord){};

	//returns a list of hit results, one for each ship attached to this ship
	std::list<HitResult*> HitMe()const throw ( std::bad_alloc );

	//attach a ship to this cell
	//returns true if attaching succeded false if not
	bool attachShip( Ship* ship ) throw();

	bool isAttached( Ship* ship ) throw();

	//detach a ship form this cell
	void detachShip( Ship* ship ) throw();

	//get list of Ships that are attached to this cell
	std::list<Ship*> getAttachedShips() const;

	virtual ~Cell() {};
private:
	//on a cell you can place any number of underwater ships
	//but just one that is above water ( you can't have 2 ships above water placed one
	//on each other )
	//also checks if the client tryes to attach same ship to the same cell twice
	//true if the ship can be attached false if not
	bool isPlaceble( Ship* ship );

	//the cell's coordinates in the gameboard
	CoordinateType coord_;

	//list of ships attached to this cell
	std::list<Ship*> ships_;

};

#endif
