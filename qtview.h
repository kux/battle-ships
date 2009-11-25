#ifndef QTVIEW_H
#define QTVIEW_H

#include <QtGui/QDialog>
#include "View.h"

class QPushButton;
class GameBoard;

class QtView : public QDialog, public View
{
    Q_OBJECT

public:
    QtView(QWidget *parent , GameBoard* gb );
    void update ( UpdateInfo info );
    ~QtView();

signals:


private slots:
	void gridClicked( int id );
	void attack();
	void moveup();
	void movedown();
	void moveleft();
	void moveright();
	void rotateleft();
	void rotateright();

private:
    //Ui::QtViewClass ui;

    static const int MAX_GSIZE = 100;

    QPushButton* board_[MAX_GSIZE][MAX_GSIZE];

    int strboard_[MAX_GSIZE][MAX_GSIZE];

    QPushButton * attackButton;
    QPushButton * moveUpButton;
    QPushButton * moveDownButton;
    QPushButton * moveLeftButton;
    QPushButton * moveRightButton;
    QPushButton * rotateLButton;
    QPushButton * rotateRButton;

    GameBoard* gameb_;

    int height_;
    int width_;

    int lastclickedi_;
    int lastclickedj_;

};

#endif // QTVIEW_H
