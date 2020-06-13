#include "z_myapp.h"

int main(int argc, char *argv[])
{
	z_myapp my_app (argc, argv);
	cout << "hoora " << endl ;
	return my_app.exec();
}
