/*
 * HitResult.cpp
 *
 *  Created on: Oct 26, 2008
 *      Author: kux
 */

#include "HitResult.h"

using namespace std;

string HitResultMissed::sMissed_ = "missed";
string HitResultSunkPart::sMissed_ = "ship hit";
string HitResultSunkShip::sMissed_ = "ship sunk";
string HitResultSunkAll::sMissed_ = "game won";
string HitResultAlreadyAttacked::sMissed_ = "already attacked";
string HitResultInvalid::sMissed_ = "invalid attack";

HitResult::HitResult() {
	// TODO Auto-generated constructor stub

}

HitResult::~HitResult() {
	// TODO Auto-generated destructor stub
}

string HitResultMissed::GetResult() {
	return sMissed_;
}

string HitResultSunkPart::GetResult() {
	return sMissed_;
}

string HitResultSunkShip::GetResult() {
	return sMissed_;
}

string HitResultSunkAll::GetResult() {
	return sMissed_;
}

string HitResultAlreadyAttacked::GetResult() {
	return sMissed_;
}

string HitResultInvalid::GetResult() {
	return sMissed_;
}

