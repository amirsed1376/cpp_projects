#include "z_theapp.h"
#include <QPushButton>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
	z_theapp theapp(argc, argv);

	return theapp.exec();
}
