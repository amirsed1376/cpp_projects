#include "string.h"

#include <iostream>
#include <string>

#include "student.h"
#include "tlinklist.h"

#include <QVector>

#include <list>
using namespace std ;

template <typename T>
int mysize (zlinklist<T> x)
{
	znode<T> * tmp = x.head ;
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
	try
	{
		try
		{
			//	throw 2.5 ;
			zlinklist<student> ll;

			zlinklist<int> li;

			li.pushback(12);
			li.popfront();


			cout << li.front() ;

			li.popfront();


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
				}

			}
			cout << " end" << endl ;

		}
		catch ( int x )
		{
			cout << " wow "<< x << endl ;
		}
		catch ( char const * x )
		{
			cout << x << endl ;
			throw 9 ;
		}
		catch (...)
		{
			cout << " internal error. contact the developer team" ;
		}
	}
	catch (...)
	{
		cout << " oh oh " ;
	}
}




