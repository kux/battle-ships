/*
 * CoordinateTypes.h
 *
 *  Created on: Nov 24, 2008
 *      Author: kux
 */

#ifndef COORDINATETYPES_H_
#define COORDINATETYPES_H_

#include <vector>

typedef std::pair<int,  int> CoordinateType;

typedef std::vector<CoordinateType> CoordinateListType;

enum Orientation { rot0, rot90, rot180, rot270 };

enum MoveDirection { mup, mdown, mleft, mright, rotatel, rotater };


#endif /* COORDINATETYPES_H_ */
