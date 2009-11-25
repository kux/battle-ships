#include "qtview.h"
#include <QtGui>

#include "GameBoard.h"

using namespace std;


QtView::QtView(QWidget *parent, GameBoard* gb )
    : QDialog(parent), gameb_( gb ), lastclickedi_(0), lastclickedj_(0)
{
	std::pair<int, int> hw = gameb_->getBoardSize();

	height_ = hw.first;
	width_ = hw.second;

	//ui.setupUi(this);
    attackButton = new QPushButton( tr("Attack"));
    moveUpButton = new QPushButton( tr("Move Up"));
    moveDownButton = new QPushButton( tr("Move Down"));
    moveLeftButton = new QPushButton( tr("Move Left"));
    moveRightButton = new QPushButton( tr("Move Right"));
    rotateLButton = new QPushButton( tr("Rotate left"));
    rotateRButton = new QPushButton( tr("Rotate right"));

    connect ( attackButton, SIGNAL( clicked()), this, SLOT(attack()));
    connect ( moveUpButton, SIGNAL( clicked()), this, SLOT(moveup()));
    connect ( moveDownButton, SIGNAL( clicked()), this, SLOT(movedown()));
    connect ( moveLeftButton, SIGNAL( clicked()), this, SLOT(moveleft()));
    connect ( moveRightButton, SIGNAL( clicked()), this, SLOT(moveright()));
    connect ( rotateLButton, SIGNAL( clicked()), this, SLOT(rotateleft()));
    connect ( rotateRButton, SIGNAL( clicked()), this, SLOT(rotateright()));

    char btext[6];
    for ( int i = 0; i < height_; ++i )
    	for ( int j = 0; j < width_; ++j )
    	{
    		strboard_[i][j] = 0;
    		sprintf( btext, "%d", strboard_[i][j] );
    		board_[i][j] = new QPushButton(tr(btext));


    	}

    QSignalMapper *boardMapper = new QSignalMapper( this );

    for ( int i = 0; i < height_; ++i )
    	for ( int j = 0; j < width_; ++j )
    	{
    		boardMapper->setMapping( board_[i][j], i * width_ + j );
    	}

    for ( int i = 0; i < height_; ++i )
        for ( int j = 0; j < width_; ++j )
        {
        	connect( board_[i][j], SIGNAL( clicked()), boardMapper, SLOT(map()) );
        }

    connect ( boardMapper, SIGNAL( mapped(int)), this, SLOT(gridClicked(int)) );


	QVBoxLayout *actionLayout = new QVBoxLayout;

	actionLayout->addWidget(attackButton);
	actionLayout->addWidget(moveUpButton);
	actionLayout->addWidget(moveDownButton);
	actionLayout->addWidget(moveLeftButton);
	actionLayout->addWidget(moveRightButton);
	actionLayout->addWidget(rotateLButton);
	actionLayout->addWidget(rotateRButton);

	QGridLayout *gridLayout = new QGridLayout;

    for ( int i = 0; i < height_; ++i )
    	for ( int j = 0; j < width_; ++j )
    	{
    		gridLayout->addWidget( board_[i][j], i, j);

    	}

	QHBoxLayout *allLayout = new QHBoxLayout;

	allLayout->addLayout( gridLayout );
	allLayout->addLayout( actionLayout );

	setLayout( allLayout );

}


void QtView::gridClicked( int id )
{
	lastclickedi_ = id / width_;
	lastclickedj_ = id % width_;
}

void QtView::attack()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	list<HitResult*> hrl = gameb_->attack( coord );
	for( list<HitResult*>::iterator i = hrl.begin(); i!=hrl.end(); ++i)
	{
		delete (*i);
	}
}

void QtView::moveup()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	gameb_->moveShips( coord, mup );
}

void QtView::movedown()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	gameb_->moveShips( coord, mdown );
}


void QtView::moveleft()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	gameb_->moveShips( coord, mleft );
}

void QtView::moveright()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	gameb_->moveShips( coord, mright );
}

void QtView::rotateleft()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	gameb_->moveShips( coord, rotatel );
}

void QtView::rotateright()
{
	CoordinateType coord( lastclickedi_, lastclickedj_ );
	gameb_->moveShips( coord, rotater );
}

void QtView::update( UpdateInfo info )
{
	CoordinateType coord = info.getCoord();
	if ( info.getType() == hit )
	{
		strboard_[coord.first][coord.second] = -999;

	}

	if ( info.getType() == attach )
	{
		strboard_[coord.first][coord.second]++;
	}
	if ( info.getType() == detach )
	{
		strboard_[coord.first][coord.second]--;
	}

	char btext[9];
	for ( int i = 0; i < height_; ++i )
	   	for ( int j = 0; j < width_; ++j )
	    {
	   		if ( strboard_[i][j] >= 0)
	   			sprintf( btext, "%d", strboard_[i][j] );
	   		else
	   			sprintf( btext, "%c", '*');
	    	board_[i][j]->setText( tr(btext ) );


	    }

}
QtView::~QtView()
{

}
