
#include <iostream>
#include <memory>

#include "Cell.h"
#include "GameBoard.h"
#include "ShipPattern.h"

using namespace std;

/*
int main ( int argc, char* argv[] ) {

	CoordinateType coord;
	CoordinateListType coordList;
	coordList.reserve(10);

	//ship patterns vector
	vector<ShipPattern> vPatterns;
	vPatterns.reserve(5);
	//bulding the ship patterns
	coord.first = 0;
	coord.second = 0; coordList.push_back(coord);
	coord.second = 1; coordList.push_back( coord );
	//build mineseeper pattern
	try {
		vPatterns.push_back( ShipPattern( "minesweeper", coordList ) );
	}
	catch(Exception &ex)
	{
		ex.printErrorMsg();
	}

	coord.second = 2; coordList.push_back( coord );
	//build destroyer pattern
	try {
		vPatterns.push_back( ShipPattern( "destroyer", coordList ) );
	}
	catch(Exception)
	{
		cout<<"bad pattern"<<endl;
	}


	coord.second = 3; coordList.push_back( coord );
	//build battlecruiser pattern
	try {
		vPatterns.push_back( ShipPattern ( "battleship", coordList ) ); }
	catch(Exception) { cout<<"bad pattern"<<endl; }

	coord.first = 1; coord.second = 1; coordList.push_back( coord );
	coord.first = -1; coord.second = 1; coordList.push_back( coord );
	coord.first = -1; coord.second = 3; coordList.push_back( coord );
	coord.first = 1; coord.second = 3; coordList.push_back( coord );
	try{
		vPatterns.push_back( ShipPattern( "avion",coordList ) ); }
	catch(Exception) { cout<<"bad pattern"<<endl; }

	GameBoard *gameBoard = NULL;

	char cop = 0;
	while (cop != '5') {
		cout<<"1 - create gameboard"<<endl;
		cout<<"2 - place ship "<<endl;
		cout<<"3 - hit at coord "<<endl;
		cout<<"4 - move ship"<<endl;
		cout<<"5 - exit "<<endl;

		cin>>cop;

		switch (cop)
		{
		case '1':
			unsigned int height, width;
			cout<<"Give the height of the terrain: "; cin>>height; cout<<endl;
			cout<<"Give the width of the terrain: "; cin>>width; cout<<endl;
			gameBoard = new GameBoard( height , width );
			gameBoard->PrintAllCells();
			break;
		case '2':
			if( gameBoard ) {
				unsigned int op;
				unsigned int X, Y, ori;
				bool underwater;
				cout<<"Give ship option: minesweeper(0), destroyer(1), battlecruiser(2), avion(3) : ";
				cin>> op;cout<<endl;
				cout<<"Give X coord at wich to place ship: ";
				cin>>X; cout<<endl;
				cout<<"Give X coord at wich to place ship: ";
				cin>>Y; cout<<endl;
				cout<<"Give orientation, rot0(0), rot90(1), rot180(2) rot270(3) ";
				cin>>ori;
				cout<<"Is it above water(0), or underwater(1) ";
				cin>>underwater;

				if ( op<4 && ori<4 )
				{
					bool placed = gameBoard->PlaceShip( vPatterns[op], CoordinateType(X,Y),
							(Orientation)ori, underwater );
					if ( !placed )cout<<"Unable to place ship there!! "<<endl;
				}
				else
					cout<<"Wrong input !!" <<endl;
				gameBoard->PrintAllCells();
			}else {
				cout<<"Board not yet created !! "<<endl;
			}

			break;
		case '3':

			if ( gameBoard ){
				int X, Y;
				cout<<"Give X coord: ";
				cin>>X; cout<<endl;
				cout<<"Give Y coord: ";
				cin>>Y; cout<<endl;
				list<HitResult*>lhr = gameBoard->Attack( CoordinateType( X,Y ) ) ;
				for ( list<HitResult*>::iterator i = lhr.begin(); i != lhr.end(); ++i )
				{
					cout<<"-------------------->"<<(*i)->GetResult()<<endl;
					delete (*i);
				}
				gameBoard->PrintAllCells();
			}else {
				cout<<"Board not yet created !! "<<endl;
			}

			break;

		case '4':

			if ( gameBoard ){
				int X, Y;
				int dir;
				cout<<"Give X coord: ";
				cin>>X; cout<<endl;
				cout<<"Give Y coord: ";
				cin>>Y; cout<<endl;
				cout<<"Give dirrection 0up 1down 2left 3right 4rotatel 5rotater: ";
				cin>>dir; cout<<endl;

				gameBoard->MoveShips( CoordinateType( X,Y ), (MoveDirection)dir ) ;

				gameBoard->PrintAllCells();
			}else {
				cout<<"Board not yet created !! "<<endl;
			}

			break;

		}
	}
	if ( gameBoard ) delete gameBoard;

}
*/
