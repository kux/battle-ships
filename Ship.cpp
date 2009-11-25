
#include "Ship.h"
#include "GameBoard.h"
#include "Cell.h"

#include <memory>
#include <algorithm>

using namespace std;


HitResult* Ship::hitMe( CoordinateType coord )throw ( std::bad_alloc )
{

	CoordinateListType::iterator is = find( hitedAt_.begin(), hitedAt_.end(), coord );

	//was already attacked
	if ( is!= hitedAt_.end() )
	{
		return new HitResultAlreadyAttacked();
	}

	//if the ship's head was hit
	//to get the result we check on the board
	//as this could be the last ship and a game win result would be suited
	if ( coord == coord_ )
	{
		CoordinateListType coords = pattern_.getRelativePositions();
		copy( coords.begin(), coords.end(), back_inserter(hitedAt_) );
		return board_->hitMe( this );
	}

	//another component was hit
	hitedAt_.push_back( coord );
	return new HitResultSunkPart();
}


