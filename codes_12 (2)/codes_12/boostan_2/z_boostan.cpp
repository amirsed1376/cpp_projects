#include "z_boostan.h"
#include "fstream"

#define sep "_________________________________________"
void z_boostan::help()
{
	qout << sep << endl ;
	qout << "help	: komak" << endl ;
	qout << "quit	: baraye kharej shodan az barname" << endl ;
	qout << "add	: add a student" << endl ;
	qout << "list	: lists students" << endl ;
	qout << sep << endl ;
}

z_boostan::z_boostan()
{
	qout << "Boostan Co. All rights reserved." << endl ;
	read_users () ;
	check_pass () ;
	operations () ;
}

void z_boostan::check_pass()
{
	qout << "enter user name" << endl ;
	QString user_name;
	qin >> user_name ;
	qout << "enter pass" << endl ;
	QString pass_word;
	qin >> pass_word ;
	bool found= false ;
	for ( int i = 0 ; i < usersp .size() ; i ++ )
	{
		if ( usersp.at(i).user == user_name && usersp.at(i).pass == pass_word )
		{
			found = true ;
			break ;
		}
	}
	if (!found )
	{
		qout << " incorrect user name or password " << endl ;
		exit (0) ;
	}
	qout << "welcome" << endl ;
}

void z_boostan::read_users()
{
	QSettings sett (set_file , QSettings::IniFormat) ;
	QStringList users = sett.value(upv,QStringList() << "admin" << "nimda" ).toStringList();
	sett.setValue(upv,users);
	for ( int i = 0 ; i < users.size() ; i+=2 )
	{
		z_userpass up ;
		up.user = users[i] ;
		up.pass = users.at(i+1);
		usersp << up ;
	}
}

void z_boostan::operations()
{
	QString cmd ;
	forever
	{
		qout << sep << endl ;
		qout << " dastoor ra vared konid (help for help)  " << endl ;
		qin >> cmd ;
		cmd = cmd.toLower() ;
		if (QString( "help").startsWith(cmd) )
			help () ;
		else if ( QString( "quit").startsWith(cmd))
			return ;
		else if ( QString( "add").startsWith(cmd))
			add_a_student () ;
		else if ( QString( "list").startsWith(cmd))
			list_students () ;
		else
			qout << " dastoor tarif nashode ast " << endl ;
	}
}

void z_boostan::add_a_student()
{
	z_student stu ;
	qout << " shorare ra vared konid " << flush ;
	qin >> stu.std_no ;
	qout << " nam ra vared konid " << flush ;
	qin >> stu.name ;
	students.insert(stu) ;
}

void z_boostan::list_students()
{
	qout << "______________________" << endl ;
	for ( auto itr = students.begin() ; itr  != students. end () ; ++ itr)
		qout << itr ->std_no << "\t" << itr->name << endl ;
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
		stu.std_no = sl.at(0).toLong() ;
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
