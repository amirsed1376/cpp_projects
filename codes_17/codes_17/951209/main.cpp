#include "string.h"
#include <iostream>

#include "linklist.h"

#include "tlinklist.h"


using namespace std ;
int main ( void )
{

	zlinklist<int> hh;

	linklist ll ;

	char ans [10] ;

	while ( true )
	{
		cout << "continue? ";
		cin >>ans ;
		if ( strcmp(ans,"no") ==0 )
			break ;

		student x;
		cin >> x.name ;
		cin>>x.avg ;
		cin>>x.addr ;
		ll.pushback(x);
	}
	cout << " end" << endl ;

}



