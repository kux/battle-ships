/*
 * View.h
 *
 *  Created on: Nov 27, 2008
 *      Author: kux
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "UpdateInfo.h"

class View {
public:
	virtual void Update( UpdateInfo info ) = 0;
	virtual ~View();

};

#endif /* VIEW_H_ */
