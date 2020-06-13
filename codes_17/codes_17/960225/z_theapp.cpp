#include "z_theapp.h"


z_theapp::z_theapp(int a, char ** b)
	: QApplication ( a , b )
{
	maindlg.show () ;
}
