/*
 * ConsoleView.cpp
 *
 *  Created on: Nov 27, 2008
 *      Author: kux
 */

#include "ConsoleView.h"
#include "CoordinateTypes.h"
#include "HitResult.h"

#include <iostream>

using namespace std;

void ConsoleView::Update( UpdateInfo info )
{
	CoordinateType coord = info.getCoord();
	if ( info.getType() == hit )
	{
		list<HitResult*> hrl = info.getHitResults();
		for( list<HitResult*>::iterator i = hrl.begin(); i!=hrl.end(); ++i)
		{
			cout<<"--------"<<(*i)->GetResult()<<endl;
		}
	}

	if ( info.getType() == attach )
	{
		cout<<"attached ship at coord: "<<coord.first<<" "<<coord.second<<endl;
	}
	if ( info.getType() == detach )
	{
		cout<<"detached ship at coord: "<<coord.first<<" "<<coord.second<<endl;
	}

}
