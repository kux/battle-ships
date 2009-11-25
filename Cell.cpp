#include "Cell.h"
#include "Ship.h"
#include "HitResult.h"
#include "UpdateInfo.h"

#include <memory>

using namespace std;


list<HitResult*> Cell::hitMe()const throw ( std::bad_alloc )
{
	list<HitResult*> lHitResults;

	if ( ships_.empty() )
	{
		lHitResults.push_back( new HitResultMissed() );
	}
	else
	{
		list<Ship*>::const_iterator end = ships_.end();
		for ( list<Ship*>::const_iterator i = ships_.begin() ; i!= end; ++i )
		{
			lHitResults.push_back( (*i)->hitMe(coord_) );
		}
	}

	return lHitResults;
}


bool Cell::attachShip( Ship* ship ) throw()
{
	if ( isPlaceble( ship ) )
	{
		ships_.push_back( ship );
		return true;
	}

	return false;
}

bool Cell::isAttached( Ship* ship ) throw()
{
	list<Ship*>::iterator rez = find( ships_.begin(), ships_.end(), ship );
	return (( rez != ships_.end() )?true:false);
}


void Cell::detachShip( Ship* ship ) throw()
{
	ships_.remove( ship );
}


list<Ship*> Cell::getAttachedShips() const
{
	return ships_;
}


bool Cell::isPlaceble( Ship* ship )
{
	//check if the same ship is placed aggain
	list<Ship*>::iterator it = find ( ships_.begin(), ships_.end(), ship );
	if ( it!= ships_.end() ) return false;

	//check if 2 above water ships are tryed to be placed on the same chell
	if ( ! ship->isDiveble() )
	{
		list<Ship*>::iterator end = ships_.end();
		for( list<Ship*>::iterator i = ships_.begin(); i!=end; ++i )
		{
			if( !(*i)->isDiveble() ) return false;
		}
	}
	return true;
}

