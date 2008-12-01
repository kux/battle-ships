

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <map>
#include <iostream>
#include <string>

class Exception
{
private:
	static bool isInitialized_ ;
	static std::map< int, std::string > exceptionMap_;

	int exCode_;

public:
	static const int INVALID_GBSIZES;
	static const int EMPTY_PATTERN;
	static const int DUPLICATE_PATTERN;
	static const int NOTCONEX_PATTERN;
	static const int FCOORD_NOTHEAD;

	Exception(int exCode):exCode_(exCode)
	{
		if ( ! isInitialized_ )
		{
			exceptionMap_[INVALID_GBSIZES] = "Provided width and length are bigger than the maximum values allowed";
			exceptionMap_[EMPTY_PATTERN] = "The provided ship pattern must at least have one coordinate";
			exceptionMap_[DUPLICATE_PATTERN] = "The provided list of coordinates for the ship pattern must not contain duplicates";
			exceptionMap_[NOTCONEX_PATTERN] = "The provided list of coordinates for the ship pattern must be conex";
			exceptionMap_[FCOORD_NOTHEAD] = "The provided list of coordinates must have (0,0,0) on the first pozition. This is the ship head";
			isInitialized_ = true;
		}

	}

	void printErrorMsg()
	{
		std::cout<<exceptionMap_[ exCode_ ]<<std::endl;
	}

	std::string getErrorMsg()
	{
		return exceptionMap_[ exCode_ ];
	}
	~Exception() {};
};

#endif /* EXCEPTION_H_ */