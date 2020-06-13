#include "string.h"

#include <iostream>
#include <string>

#include "student.h"
#include "tlinklist.h"


using namespace std ;

template <typename T>
int mysize (zlinklist<T> x)
{
	znode<T> * tmp = x.get_head();
	int s = 0 ;
	while (tmp != nullptr)
	{
		s ++ ;
		tmp = tmp->next ;
	}
	return s ;
}


void help ()
{
	cout << "quit for quit" << endl ;
	cout << "addback to add student " << endl ;
	cout << "addfront to add student " << endl ;
	cout << "help to show this menu " << endl ;
	cout << "chap to print linklist " << endl ;
	cout << "popfront " << endl ;
	cout << "size " << endl ;
}

int main ( void )
{

	zlinklist2<student,10> ll ;

	zlinklist2<student,10> ll2 (20);

	zlinklist2<student> ll3 (40) ;
	zlinklist2<student> ll4  ;

	zlinklist2<> ll5  ;

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
		else if ( string(ans) == "size" )
		{
			cout << "size is " << mysize (ll ) << endl ;
			cout << "size is " << ll.size() << endl ;
		}
	}
	cout << " end" << endl ;
}




