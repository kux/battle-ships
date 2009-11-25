#include "qtview.h"
#include "GameBoard.h"
#include "ConsoleView.h"
#include "View.h"

#include <QtGui>
#include <QApplication>
#include <vector>
#include <memory>



using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
	} catch(Exception &ex) { ex.printErrorMsg(); }

	coord.second = 2; coordList.push_back( coord );
	//build destroyer pattern
	try { vPatterns.push_back( ShipPattern( "destroyer", coordList ) ); }
	catch(Exception &ex) { ex.printErrorMsg(); }

	coord.second = 3; coordList.push_back( coord );
	//build battlecruiser pattern
	try { vPatterns.push_back( ShipPattern ( "battleship", coordList ) ); }
	catch(Exception &ex) { ex.printErrorMsg(); }

	coord.first = 1; coord.second = 1; coordList.push_back( coord );
	coord.first = -1; coord.second = 1; coordList.push_back( coord );
	coord.first = -1; coord.second = 3; coordList.push_back( coord );
	coord.first = 1; coord.second = 3; coordList.push_back( coord );
	try{ vPatterns.push_back( ShipPattern( "avion",coordList ) ); }
	catch(Exception &ex) { ex.printErrorMsg(); }

    auto_ptr<GameBoard> board ( new GameBoard( 5, 5 ) );

    QtView w(NULL, board.get() );

    auto_ptr<View>  consoleView ( new ConsoleView() );

    board->attachView( &w );
    board->attachView( consoleView.get() );

    CoordinateType cc(0,0);
    board->placeShip( vPatterns.at(0), cc,	rot0, false );
    //cc.first = 1; cc.second = 1;
    //board->PlaceShip( vPatterns.at(1), cc,	rot90, false );
    cc.first = 2; cc.second = 0;
    board->placeShip( vPatterns.at(1), cc,	rot90, false );

    cc.first = 1; cc.second = 2;
    board->placeShip( vPatterns.at(3), cc,	rot90, true );

    w.show();
    return a.exec();
}
