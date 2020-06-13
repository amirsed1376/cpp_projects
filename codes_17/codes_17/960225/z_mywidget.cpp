#include "z_mywidget.h"
#include <QMessageBox>
#include <iostream>
using namespace  std;

z_mywidget::z_mywidget()
	:btn1("salam       .",this)
{

//	vl = new QVBoxLayout(this) ;
	hl = new QHBoxLayout(this) ;
	btn2 = new QPushButton ("bye") ;
	hl->addWidget(&btn1);
	hl->addWidget(btn2);

//	setLayout(hl);
//	btn1.setGeometry(50,50,80,90);
//	btn2->setGeometry(200,200,100,100);

	connect(&btn1,SIGNAL(clicked()),this,SLOT(say_hello())) ;
}

void z_mywidget::say_hello()
{
	cout << " saalam " << endl  ;
	QMessageBox::warning(this,"salam","chetori?");
	cout << "bye " << endl ;
}
