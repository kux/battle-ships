/*
 * HitResult.cpp
 *
 *  Created on: Oct 26, 2008
 *      Author: kux
 */

#include "HitResult.h"

using namespace std;

const string HitResultMissed::sMissed_ = "missed";
const string HitResultSunkPart::sShipHitMsg_ = "ship hit";
const string HitResultSunkShip::sShipSunkMsg_ = "ship sunk";
const string HitResultSunkAll::sWonMsg_ = "game won";
const string HitResultAlreadyAttacked::sAlreadyAttackedMsg_ = "already attacked";
const string HitResultInvalid::sInvalidMsg_ = "invalid attack";

HitResult::HitResult() {

}

HitResult::~HitResult() {

}

string HitResultMissed::getResult() {
	return sMissed_;
}

string HitResultSunkPart::getResult() {
	return sShipHitMsg_;
}

string HitResultSunkShip::getResult() {
	return sShipSunkMsg_;
}

string HitResultSunkAll::getResult() {
	return sWonMsg_;
}

string HitResultAlreadyAttacked::getResult() {
	return sAlreadyAttackedMsg_;
}

string HitResultInvalid::getResult() {
	return sInvalidMsg_;
}

