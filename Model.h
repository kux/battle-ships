
#ifndef MODEL_H_
#define MODEL_H_

#include <list>
#include "UpdateInfo.h"
#include "View.h"

class Model {
public:
	void notify( UpdateInfo info );
	void attachView( View* newview )
	{
		viewList_.push_back( newview );
	}

	void detachView( View* view )
	{
		viewList_.remove ( view );
	}

private:
	std::list<View*> viewList_;
};

#endif /* MODEL_H_ */
