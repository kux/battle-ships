
#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <exception>
#include <list>

#include "CoordinateTypes.h"
#include "Cell.h"
#include "ShipPattern.h"
#include "HitResult.h"
#include "Exception.h"
#include "Ship.h"
#include "View.h"
#include "Model.h"

/*
 * class modeling the gameboard
 */
class GameBoard: public Model {
public:
	/*
	 * GameBoard constructor
	 * takes the height and width of the board to be created as parameters
	 * if height or width are bigger than the maximum allowed value of 100
	 * Exception is thrown
	 */
	GameBoard(int height, int width) throw (Exception, std::bad_alloc);

	/*
	 * place a ship based on a ShipPattern, coordinates and an Orientation
	 * returns true if the ship was placed and false if it could not be places
	 * ( overlapped with another ship or is out of the border )
	 */
	bool placeShip(const ShipPattern& pattern, const CoordinateType& coord,
			Orientation orientation, bool diveble) throw ();

	/*
	 * move ship that has cell at given coordinates
	 */
	void moveShips(const CoordinateType& coord, MoveDirection dir);

	/*
	 * attack the cell at given coordinates
	 * forwards the request to the underlaying Cell at the given coordinates
	 */
	std::list<HitResult*> attack(const CoordinateType& coord)
			throw (std::bad_alloc);

	//sink ship pointed by Ship* ship
	HitResult* hitMe(Ship* ship) throw (std::bad_alloc);

	std::pair<int, int> getBoardSize() {
		return std::pair<int, int>(height_, width_);
	}

	~GameBoard();

private:

	//attach ship to the gameboard
	bool attachShip(Ship* ship) throw ();

	//detach the ship from the gameboard
	void detachShip(Ship* ship) throw ();

	//the maximum size of the gameboard is MAX_GSIZE*MAX_GSIZE
	static const int MAX_GSIZE = 100;

	//gameboard matrix
	Cell* board_[MAX_GSIZE][MAX_GSIZE];

	//vector of pointers to live ships that belong to this board
	std::list<Ship*> vShips_;

	//vector of pointers to sunken sinps that belong to this board
	std::list<Ship*> vSunkenShips_;

	//gameboard height and width
	int height_;
	int width_;

	//the gameboard's views
	std::list<View*> viewList_;

};

#endif
