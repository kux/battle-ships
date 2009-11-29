#ifndef SHIPPATTERN_H_
#define SHIPPATTERN_H_

#include <algorithm>
#include <utility>
#include <string>

#include "Exception.h"
#include "CoordinateTypes.h"

//class used to model a ship pattern
//instances of this class will be passed to GameBoard's PlaceShip method
class ShipPattern {
public:
	//defalult constructor
	ShipPattern();

	//the first Coordinate in the objCoord must be (0,0)
	//this will be the ship's "center" from wich it will be rotated
	//depending on the way you want to place it on the game-board when
	//you use the pattern to create an actuall ship on the game-board
	ShipPattern(const std::string& sShipTypeName,
			const CoordinateListType& objCoord) throw (Exception);

	//given a coordinate and an orientation this method calculates the
	//absolute positions that the ship occupies based on it's pattern ( the relative
	CoordinateListType getAbsolutePozitions(const CoordinateType& coord,
			Orientation orientation) const;

	CoordinateListType getRelativePositions() const {
		return coordList_;
	}

	int getNumberOfComponents() const {
		return coordList_.size();
	}

private:

	CoordinateListType coordList_;

	//name of this pattern ( ex: destroyer, battlecruiser, whatever )
	std::string sShipTypeName_;

	//check if the ship pattern is valid
	//it checks for duplicate
	//checkes that the given coordinates are conex
	//in order for the ship patterns to be valid, the coordinates MUST be conex
	bool validatePattern(const CoordinateListType& objCoord_);

	//checks if 2 given coordinates are adiacent on the board
	bool isAdiacent(const CoordinateType& x, const CoordinateType& y);

};

#endif
