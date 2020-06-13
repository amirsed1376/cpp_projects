#include "z_dars_daneshjoo.h"
#include <fstream>
#include <defs.h>
#include <QStringList>
z_dars_daneshjoo::z_dars_daneshjoo()
{

}


void z_dars_daneshjoo_relation::fill_from_file()
{
	ifstream the_file (dars_daneshjoo_rel);
	if (!the_file.is_open())
		return ;
	while (!the_file.eof())
	{
		z_dars_daneshjoo dd;

		char str [ 10000 ] ;
		the_file.getline(str,10000) ;
		QStringList sl = QString(str).split(',');
		if (sl.size()!=2)
			continue;
		dd.cid = sl.at(0).toLongLong() ;
		dd.std_no = sl.at(1).toLongLong () ;
		insert(dd) ;
	}
	the_file.close();
}

void z_dars_daneshjoo_relation::write_to_file()
{
	ofstream the_file (dars_daneshjoo_rel);
	if (!the_file.is_open())
		return ;
	for (auto itr = begin () ; itr != end () ; ++ itr )
		the_file << itr->cid << "," << itr->std_no << endl ;
	the_file.close();
}
