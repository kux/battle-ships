/*
 * HitResult.cpp
 *
 *  Created on: Oct 26, 2008
 *      Author: kux
 */

#include "HitResult.h"

using namespace std;

const string HitResultMissed::sMissed_ = "missed";
const string HitResultSunkPart::sMissed_ = "ship hit";
const string HitResultSunkShip::sMissed_ = "ship sunk";
const string HitResultSunkAll::sMissed_ = "game won";
const string HitResultAlreadyAttacked::sMissed_ = "already attacked";
const string HitResultInvalid::sMissed_ = "invalid attack";

HitResult::HitResult() {
	// TODO Auto-generated constructor stub

}

HitResult::~HitResult() {
	// TODO Auto-generated destructor stub
}

string HitResultMissed::getResult() {
	return sMissed_;
}

string HitResultSunkPart::getResult() {
	return sMissed_;
}

string HitResultSunkShip::getResult() {
	return sMissed_;
}

string HitResultSunkAll::getResult() {
	return sMissed_;
}

string HitResultAlreadyAttacked::getResult() {
	return sMissed_;
}

string HitResultInvalid::getResult() {
	return sMissed_;
}

