#include "z_boostan.h"

#define sep "_________________________________________"
void z_boostan::help()
{
	qout << sep << endl ;
	qout << "help	: komak" << endl ;
	qout << "quit	: baraye kharej shodan az barname" << endl ;
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
		else
			qout << " dastoor tarif nashode ast " << endl ;
	}
}
