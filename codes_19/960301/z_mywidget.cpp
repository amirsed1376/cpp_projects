#include "z_mywidget.h"
#include <QMessageBox>
#include <iostream>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QTimer>
#include <z_mydialog.h>
using namespace  std;


extern int cnt ;

z_mywidget::z_mywidget()
	:btn1("salam       .",this)
{

	hl = new QHBoxLayout(this) ;
	btn2 = new QPushButton ("bye") ;
	le = new QLineEdit () ;
	le2= new QLineEdit() ;
	hl->addWidget(&btn1);
	hl->addWidget(btn2);
	hl->addWidget(le);
	hl->addWidget(le2);
	le->setText("1");



	tme = new QTimer ;
	tme->start ( 1000 ) ;
	QObject::connect (tme,SIGNAL (timeout()),this, SLOT(incer()));
	connect(&btn1,SIGNAL(clicked()),this,SLOT(say_hello())) ;
	connect(le,SIGNAL(textChanged(QString)),this,SLOT (duplicator(QString)));
}

z_mywidget::~z_mywidget()
{
	delete tme ;
	tme = nullptr;
}

void z_mywidget::say_hello()
{
	cout << " saalam " << endl  ;
	QMessageBox::warning(this,"salam","chetori?");
	cout << "bye " << endl ;
	z_mydialog * md = new z_mydialog ;
	md->show();

}

void z_mywidget::incer()
{
	le->setText( QString::number(le->text().toInt()+1) ) ;
}

void z_mywidget::duplicator(QString x)
{
	le2->setText(QString::number( cnt)) ;
}
