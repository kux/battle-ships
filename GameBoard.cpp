#include "GameBoard.h"

//debug
#include <iostream>
using namespace std;

GameBoard::GameBoard(int height, int width) throw (Exception) :
	height_(height), width_(width) {

	//test if the provided sizes aren't bigger than the maximum size allowed
	if (height > MAX_GSIZE || width > MAX_GSIZE)
		throw Exception(Exception::INVALID_GBSIZES);

	for (int i = 0; i < height_; ++i)
		for (int j = 0; j < width_; ++j)
			board_[i][j] = new Cell(CoordinateType(i, j));

}

bool GameBoard::placeShip(const ShipPattern& pattern,
		const CoordinateType& coord, enum Orientation orientation, bool diveble) throw () {

	Ship* newShip = new Ship(this, pattern, coord, orientation, diveble);

	if (attachShip(newShip)) {
		vShips_.push_back(newShip);
		return true;
	}

	delete newShip;
	return false;

}

void GameBoard::moveShips(const CoordinateType& coord, MoveDirection dir) {
	list<Ship*> attachedShips =
			board_[coord.first][coord.second]->getAttachedShips();

	list<Ship*>::iterator end = attachedShips.end();
	for (list<Ship*>::iterator ship_iter = attachedShips.begin(); ship_iter
			!= end; ++ship_iter) {
		list<Ship*>::iterator rez = find(vSunkenShips_.begin(),
				vSunkenShips_.end(), (*ship_iter));
		//unable to move if sunk
		if (rez != vSunkenShips_.end())
			continue;

		//save current state of the ship in case the move fails
		Ship rollback(**ship_iter);
		detachShip(*ship_iter);
		(*ship_iter)->moveShip(dir);

		//attach ship with it's new coordinates
		if (!attachShip(*ship_iter)) {
			//if attachment failed reattach to old coordinates
			**ship_iter = rollback;
			attachShip(*ship_iter);
		}
	}
}

list<HitResult*> GameBoard::attack(const CoordinateType& coord){
	list<HitResult*> lHResult;
	if ((coord.first >= 0 && coord.first < height_) && (coord.second >= 0
			&& coord.second < width_))
		lHResult = board_[coord.first][coord.second]->hitMe();

	//notify views about the state change
	UpdateInfo info(hit, coord, lHResult);
	notify(info);
	return lHResult;
}

HitResult* GameBoard::hitMe(Ship* ship){
	vSunkenShips_.push_back(ship);
	if (vSunkenShips_.size() == vShips_.size())
		return new HitResultSunkAll();
	else
		return new HitResultSunkShip();
}

bool GameBoard::attachShip(Ship* ship) throw () {
	CoordinateListType absoluteCoords = ship->getAbsoluteCoordinates();
	CoordinateListType::const_iterator end = absoluteCoords.end();

	for (CoordinateListType::const_iterator i = absoluteCoords.begin(); i
			!= end; ++i) {
		if (i->first < 0 || i->first >= height_ || i->second < 0 || i->second
				>= width_ || (!board_[i->first][i->second]->attachShip(ship))) {
			// if the ship was not attacheble rollback to the previsorious state
			//( detach from cells that got attached until now )
			detachShip(ship);
			return false;
		}
	}

	//notify views
	for (CoordinateListType::const_iterator i = absoluteCoords.begin(); i
			!= end; ++i) {
		UpdateInfo info(attach, (*i));
		notify(info);
	}

	return true;

}

void GameBoard::detachShip(Ship* ship) throw () {
	CoordinateListType absoluteCoords = ship->getAbsoluteCoordinates();
	CoordinateListType::const_iterator end = absoluteCoords.end();

	for (CoordinateListType::const_iterator i = absoluteCoords.begin(); i
			!= end; ++i) {
		if (i->first >= 0 && i->first < height_ && i->second >= 0 && i->second
				< width_ && board_[i->first][i->second]->isAttached(ship)) {
			board_[i->first][i->second]->detachShip(ship);
			//notify views
			UpdateInfo info(detach, (*i));
			notify(info);

		}
	}
}

GameBoard::~GameBoard() {
	for (int i = 0; i < height_; ++i)
		for (int j = 0; j < width_; ++j)
			delete board_[i][j];

	list<Ship*>::iterator end = vShips_.end();
	for (list<Ship*>::iterator i = vShips_.begin(); i != end; ++i)
		delete (*i);

}
