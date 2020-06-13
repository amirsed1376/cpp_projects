#include "z_dars.h"
#include "defs.h"
#include <fstream>
#include <QStringList>
using namespace std ;
z_dars::z_dars()
{

}

void z_darsha::fill_from_file()
{
	ifstream dars_file (darsha_file);
	if (!dars_file.is_open())
		return ;
	while (!dars_file.eof())
	{
		z_dars dars ;
		char str [ 10000 ] ;
		dars_file.getline(str,10000) ;
		QStringList sl = QString(str).split(',');
		if (sl.size()!=3)
			continue;
		dars.cid = sl.at(0).toLongLong() ;
		dars.name = sl.at(1) ;
		dars.vahed = sl.at(2 ).toInt() ;
		insert(dars) ;
	}
	dars_file.close();
}

void z_darsha::write_to_file()
{
	ofstream dars_file (darsha_file);
	if (!dars_file.is_open())
		return ;
	for (auto itr = begin () ; itr != end () ; ++ itr )
		dars_file << itr->cid << "," << itr->name.toStdString() << "," << itr->vahed <<  endl ;
	dars_file.close();
}
