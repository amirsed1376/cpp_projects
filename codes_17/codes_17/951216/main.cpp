#include "string.h"

#include <iostream>
#include <string>

#include "student.h"
#include "tlinklist.h"

#include <QVector>

#include <list>
using namespace std ;


void help ()
{
	cout << "quit for quit" << endl ;
	cout << "addback to add student " << endl ;
	cout << "addfront to add student " << endl ;
	cout << "help to show this menu " << endl ;
	cout << "chap to print linklist " << endl ;
	cout << "popfront " << endl ;
}

int main ( void )
{

	zlinklist<student> ll;

	zlinklist<int> li;
	li.pushback(12);

	char ans [10] ;

	while ( true )
	{
		help () ;
		cout << "command? ";
		cin >>ans ;
		string anst ( ans ) ;
		if ( strcmp(ans,"quit") ==0 )
			break ;
		else if ( strcmp(ans,"addfront") == 0 )
		{
			student x;
			cin >> x.name ;
			cin>>x.avg ;
			cin>>x.addr ;

			ll << x ;
		}
		else if ( strcmp(ans,"addback") == 0 )
		{
			student x;
			cin >> x.name ;
			cin>>x.avg ;
			cin>>x.addr ;

			ll += x ;
		}
		else if ( strcmp (ans,"help") == 0 )
		{
			help () ;
		}
		else if ( anst == "chap" )
		{
			ll.chap();
		}
		else if ( string(ans) == "popfront" )
		{
			 -- ll ;
		}
	}
	cout << " end" << endl ;


}




