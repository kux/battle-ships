

#ifndef HITRESULT_H_
#define HITRESULT_H_

#include <string>

class HitResult {
public:
	HitResult();

	virtual std::string GetResult() = 0;
	virtual ~HitResult();
};


class HitResultMissed:public HitResult
{
public:
	std::string GetResult();
private:
	static std::string sMissed_;

};


class HitResultSunkPart:public HitResult
{
public:
	std::string GetResult();
private:
	static std::string sMissed_;
};


class HitResultSunkShip:public HitResult
{
public:
	std::string GetResult();
private:
	static std::string sMissed_;
};


class HitResultSunkAll:public HitResult
{
public:
	std::string GetResult();
private:
	static std::string sMissed_;

};

class HitResultAlreadyAttacked:public HitResult
{
public:
	std::string GetResult();
private:
	static std::string sMissed_;
};

class HitResultInvalid:public HitResult
{
public:
	std::string GetResult();
private:
	static std::string sMissed_;
};

#endif
