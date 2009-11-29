#include "ShipPattern.h"
#include <cmath>

using namespace std;

ShipPattern::ShipPattern() {
	coordList_.push_back(CoordinateType(0, 0));
}

ShipPattern::ShipPattern(const std::string& sShipTypeName,
		const CoordinateListType& objCoord) throw (Exception) :
	sShipTypeName_(sShipTypeName) {
	validatePattern(objCoord);
	coordList_ = objCoord;
}

CoordinateListType ShipPattern::getAbsolutePozitions(
		const CoordinateType& coord, Orientation orientation) const {
	CoordinateListType newCoordsList;

	//iterate through the relative coordinates( ship pattern ) and calculate the
	//absolute ones
	CoordinateListType::const_iterator end = coordList_.end();
	for (CoordinateListType::const_iterator i = coordList_.begin(); i != end; ++i) {

		switch (orientation) {
		case rot0: {
			CoordinateType newCoord((*i).first + coord.first, (*i).second
					+ coord.second);
			newCoordsList.push_back(newCoord);
			break;
		}
		case rot90: {
			CoordinateType newCoord((*i).second + coord.first, -(*i).first
					+ coord.second);
			newCoordsList.push_back(newCoord);
			break;
		}
		case rot180: {
			CoordinateType newCoord(-(*i).first + coord.first, -(*i).second
					+ coord.second);
			newCoordsList.push_back(newCoord);
			break;
		}
		case rot270: {
			CoordinateType newCoord(-(*i).second + coord.first, (*i).first
					+ coord.second);
			newCoordsList.push_back(newCoord);
			break;
		}
		}
	}

	return newCoordsList;

}

bool ShipPattern::validatePattern(const CoordinateListType& objCoord_) {
	//must not be empty and first coords must be (0,0) ship head
	if (objCoord_.empty())
		throw Exception(Exception::EMPTY_PATTERN);
	if (objCoord_[0].first != 0 || objCoord_[0].second != 0)
		throw Exception(Exception::FCOORD_NOTHEAD);

	//check for duplicates
	for (CoordinateListType::const_iterator i = objCoord_.begin(); i
			!= objCoord_.end(); ++i) {
		CoordinateListType::const_iterator frez = find(i + 1, objCoord_.end(),
				*i);
		if (frez != objCoord_.end())
			throw Exception(Exception::DUPLICATE_PATTERN);
	}

	//check that the pattern is conex
	vector<bool> vHasAdiacent(objCoord_.size(), false);

	for (size_t i = 0; i < objCoord_.size(); ++i) {
		for (size_t j = i + 1; j < objCoord_.size(); ++j)
			if (isAdiacent(objCoord_[i], objCoord_[j]))
				vHasAdiacent[i] = vHasAdiacent[j] = true;

	}

	for (size_t i = 0; i < vHasAdiacent.size(); ++i) {
		if (!vHasAdiacent[i])
			throw Exception(Exception::NOTCONEX_PATTERN);
	}

	return true;
}

bool ShipPattern::isAdiacent(const CoordinateType& x, const CoordinateType& y) {
	if ((x.first == y.first) && (abs(x.second - y.second) == 1))
		return true;

	if ((x.second == y.second) && (abs(x.first - y.first) == 1))
		return true;

	return false;
}
