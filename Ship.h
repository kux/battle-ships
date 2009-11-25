
#ifndef SHIP_H_
#define SHIP_H_

#include <list>
#include <string>
#include "HitResult.h"
#include "ShipPattern.h"

class GameBoard;

//class that will represent a ship
//an instantiated object of this class encapsulates all the ship's information:
//head coordinates( captain's headquarters ), pattern ( that encapsulates
//the ship's relative coordinates, offsets from the head cell ), orientation
//and weather this ship is above or below water
//in order to attach this ship to the board you need to call
//the GameBoard's AttachShip that takes a ship as parameter
//and based on the ship's absolute coordinates
//( that are calculated from the head coordinates, pattern, orientation )
//attaches the ship to the board by making the Cell's found at the absolute
//coordinates point to the ship object
class Ship
{
public:
	Ship(): board_(NULL) {};

	Ship( GameBoard* board, const ShipPattern& pattern,
			CoordinateType coord, Orientation orientation, bool diveble ):

				board_(board), pattern_(pattern),
				coord_(coord), orientation_(orientation),
				diveble_(diveble), bsunk_(false){};

	// returns weather the ship is overwriteble or not
	// on a cell, only one non-diveble cell can exist
	bool isDiveble() const
	{
		return diveble_;
	}

	//return the ships coordinates
	CoordinateListType getAbsoluteCoordinates() const
	{
		return pattern_.getAbsolutePozitions( coord_, orientation_ );
	}

	//return the coordinates of the ship's head
	CoordinateType getHeadCoords() const
	{
		return coord_;
	}

	void moveShip( MoveDirection dir )
	{
		switch( dir )
		{
		case mup: coord_.first--; break;
		case mdown: coord_.first++; break;
		case mleft: coord_.second--;break;
		case mright: coord_.second++;break;
		case rotatel:
			if ( orientation_ == rot0 ) orientation_ = rot90;
			else if ( orientation_ == rot90 ) orientation_ = rot180;
			else if ( orientation_ == rot180 ) orientation_ = rot270;
			else if ( orientation_ == rot270 ) orientation_ = rot0;
			break;
		case rotater:
			if ( orientation_ == rot0 ) orientation_ = rot270;
			else if ( orientation_ == rot90 ) orientation_ = rot0;
			else if ( orientation_ == rot180 ) orientation_ = rot90;
			else if ( orientation_ == rot270 ) orientation_ = rot180;
			break;
		}
	}

	//hit the ship at the given coordinate
	HitResult* hitMe( CoordinateType coord )throw ( std::bad_alloc );

	~Ship() {};

private:

	//pointer to the board that the ship belongs to
	GameBoard* board_;

	//the ship's pattern
	ShipPattern pattern_;

	//the ship's head coordinates
	CoordinateType coord_;

	//Orientation
	Orientation orientation_;

	//is it diveble or not ( diveble means that the ship is underwater,
	//else means that the ship is above water )
	bool diveble_;

	//the ship is sunk or not
	bool bsunk_;

	//list of the hited coordinates, it is stored as relative coordinates
	CoordinateListType hitedAt_;

};

#endif /* SHIP_H_ */

