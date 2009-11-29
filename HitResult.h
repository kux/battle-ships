
#ifndef HITRESULT_H_
#define HITRESULT_H_

#include <string>

class HitResult {
public:
	HitResult();

	virtual std::string getResult() = 0;
	virtual ~HitResult();
};

class HitResultMissed: public HitResult {
public:
	std::string getResult();
private:
	static const std::string sMissed_;

};

class HitResultSunkPart: public HitResult {
public:
	std::string getResult();
private:
	static const std::string sShipHitMsg_;
};

class HitResultSunkShip: public HitResult {
public:
	std::string getResult();
private:
	static const std::string sShipSunkMsg_;
};

class HitResultSunkAll: public HitResult {
public:
	std::string getResult();
private:
	static const std::string sWonMsg_;

};

class HitResultAlreadyAttacked: public HitResult {
public:
	std::string getResult();
private:
	static const std::string sAlreadyAttackedMsg_;
};

class HitResultInvalid: public HitResult {
public:
	std::string getResult();
private:
	static const std::string sInvalidMsg_;
};

#endif
