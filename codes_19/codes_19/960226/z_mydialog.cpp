#include "z_mydialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
z_mydialog::z_mydialog(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout * vl = new QVBoxLayout ;
	vl->addWidget(new QLineEdit ) ;
	setLayout(vl);
}
