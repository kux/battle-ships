
#include "Exception.h"

bool Exception::isInitialized_ = false;
std::map<int , std::string> Exception::exceptionMap_;

const int Exception::INVALID_GBSIZES = 0 ;
const int Exception::EMPTY_PATTERN = 1;
const int Exception::DUPLICATE_PATTERN = 2;
const int Exception::NOTCONEX_PATTERN = 3;
const int Exception::FCOORD_NOTHEAD = 4;
