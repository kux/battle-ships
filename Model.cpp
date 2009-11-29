#include "Model.h"

using namespace std;

void Model::notify(UpdateInfo info) {
	list<View*>::iterator end = viewList_.end();
	for (list<View*>::iterator i = viewList_.begin(); i != end; ++i) {
		(*i)->update(info);
	}
}
