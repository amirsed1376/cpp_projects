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
	qout << "remove	: remove a student" << endl ;
	qout << "darsadd : add a dars" << endl ;
	qout << "darslist : list dars ha" << endl ;
	qout << "akhze_vahed : akhze vahed" << endl ;
	qout << "doroos : liste doroose akhz shode afrad " << endl; ;
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
		else if ( QString( "remove").startsWith(cmd))
			remove_a_student () ;
		else if ( QString( "darsadd").startsWith(cmd))
			add_a_dars () ;
		else if ( QString( "darslist").startsWith(cmd))
			list_dars_ha () ;
		else if ( QString( "akhze_vahed").startsWith(cmd))
			akhze_dars () ;
		else if ( QString( "doroos").startsWith(cmd))
			doroos () ;
		else
			qout << " dastoor (" <<cmd<< ") tarif nashode ast " << endl ;
	}
}

void z_boostan::add_a_student()
{
	z_student stu ;
	qout << " shorare ra vared konid " << flush ;
	qin >> stu.std_no ;
	qout << " nam ra vared konid " << flush ;
	stu.name = qin.readLine().trimmed() ;
	while (stu.name.size()==0)
		stu.name = qin.readLine().trimmed() ;
	if ( students.insert(stu).second == false )
	{
		qout << " daneshjoo ghablan sabt shode ast " << endl ;
		return ;
	}
	qout << " sabt shod" << endl ;
	students.write_to_file();
}

void z_boostan::list_students()
{
	qout << "______________________" << endl ;
	for ( auto itr = students.begin() ; itr  != students. end () ; ++ itr)
		qout << itr ->std_no << "\t" << itr->name << endl ;
}

void z_boostan::remove_a_student()
{
	qout << " shomared daneshjoo ra vard kon " << flush ;
	z_student stu ;
	qin >> stu.std_no ;
	if ( students.erase(stu) == 1 )
		qout << " success " << endl  ;
	else
		qout << " no such student " << endl ;
	students.write_to_file();
}

void z_boostan::add_a_dars()
{
	z_dars dars ;
	qout << " shorare dars ra vared konid " << flush ;
	qin >> dars.cid ;
	qout << " nam e dars ra vared konid " << flush ;
	dars.name = qin.readLine().trimmed() ;
	while (dars.name.size()==0)
		dars.name = qin.readLine().trimmed() ;

	qout << " tedade vahed ra vared konid " << flush ;
	qin >> dars.vahed  ;
	if ( darsha.insert(dars).second == false )
	{
		qout << " dars ghablan sabt shode ast " << endl ;
		return ;
	}
	qout << " sabt shod" << endl ;
	darsha.write_to_file();

}

void z_boostan::list_dars_ha()
{
	qout << "______________________" << endl ;
	for ( auto itr = darsha.begin() ; itr  != darsha. end () ; ++ itr)
		qout << itr ->cid << "\t" << itr->name << "\t" << itr->vahed <<endl ;
}

bool is_all_digits ( QString const & str )
{
	for (int i = 0 ; i < str.size() ; i++ )
		if ( !str[i].isDigit())
			return false ;
	return true ;
}

void z_boostan::akhze_dars()
{
	z_dars_daneshjoo dd ;
	// daryafte shomare daneshjoo va shomare dars
	{
		qout << " shomare danesh joo : " << flush ;
		QString stustr ;
		qin >> stustr ;
		if (is_all_digits(stustr))
		{
			dd.std_no = stustr.toLongLong();
			// check existance of daneshjoo
			{
				z_student stu ;
				stu.std_no = dd.std_no ;
				if (students.find(stu) == students.end() )
				{
					qout << " daneshjoo yaft nashod" << endl ;
					return ;
				}
			}
		}
		else
		{
			dd.std_no = students.find_std_no (stustr);
			if ( dd.std_no < 0 )
			{
				qout << " een danesh joo vojood nadarad" << endl ;
				return ;
			}
		}
		qout << " shomare dars : " << flush ;
		qin >> dd.cid ;
	}

	// check existance of dars
	{
		z_dars dars ;
		dars.cid = dd.cid ;
		if (darsha.find(dars) == darsha.end() )
		{
			qout << " dars yaft nashod" << endl ;
			return ;
		}
	}
	if ( ddr.insert(dd).second == false )
	{
		qout << "dars ghablan akhz shode bood " << endl ;
	}
}

void z_boostan::doroos()
{
	for ( auto itr = ddr.begin() ; itr != ddr.end() ; ++ itr )
	{
		z_student stu ;
		stu.std_no = itr->std_no ;
		z_dars dars ;
		dars.cid = itr->cid ;
		qout << students.find(stu)->name << "\t" << darsha.find(dars)->name << endl ;
	}
}
