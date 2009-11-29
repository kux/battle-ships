/*
 * ModelUpdateInfo.h
 *
 *  Created on: Nov 27, 2008
 *      Author: kux
 */

#ifndef MODELUPDATEINFO_H_
#define MODELUPDATEINFO_H_

#include <list>
#include "CoordinateTypes.h"

class HitResult;

enum UpdateType {
	hit, attach, detach
};

class UpdateInfo {
public:
	UpdateInfo(UpdateType type, CoordinateType coord, std::list<HitResult*> hrl) :
		type_(type), coord_(coord), hrList_(hrl) {
	}

	UpdateInfo(UpdateType type, CoordinateType coord) :
		type_(type), coord_(coord) {
	}

	UpdateType getType() {
		return type_;
	}
	CoordinateType getCoord() {
		return coord_;
	}
	std::list<HitResult*> getHitResults() {
		return hrList_;
	}
private:
	UpdateType type_;
	CoordinateType coord_;
	std::list<HitResult*> hrList_;

};

#endif /* MODELUPDATEINFO_H_ */
