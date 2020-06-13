#include "z_theapp.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
	z_theapp theapp(argc, argv);

	return theapp.exec();
}
