#include "z_student.h"
#include <fstream>
#include "defs.h"
#include <QStringList>

z_student::z_student()
{

}

void z_students::fill_from_file()
{
	ifstream stu_file (students_file);
	if (!stu_file.is_open())
		return ;
	while (!stu_file.eof())
	{
		z_student stu ;
		char str [ 10000 ] ;
		stu_file.getline(str,10000) ;
		QStringList sl = QString(str).split(',');
		if (sl.size()!=2)
			continue;
		stu.std_no = sl.at(0).toLongLong() ;
		stu.name = sl.at(1) ;
		insert(stu) ;
	}
	stu_file.close();
}

void z_students::write_to_file()
{
	ofstream stu_file (students_file);
	if (!stu_file.is_open())
		return ;
	for (auto itr = begin () ; itr != end () ; ++ itr )
		stu_file << itr->std_no << "," << itr->name.toStdString() << endl ;
	stu_file.close();
}

qint64 z_students::find_std_no(QString & stustr)
{
	for ( auto itr = begin() ; itr != end () ; ++ itr )
		if (itr->name == stustr )
			return itr->std_no ;
	return -1 ;
}
