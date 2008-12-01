
#include "Model.h"

using namespace std;


void Model::Notify( UpdateInfo info )
{
	list<View*>::iterator end = viewList_.end();
	for ( list<View*>::iterator i = viewList_.begin(); i!=end; ++i )
	{
		(*i)->Update( info );
	}
}
