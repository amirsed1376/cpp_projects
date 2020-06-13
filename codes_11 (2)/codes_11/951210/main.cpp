#include "string.h"

#include <iostream>

#include "student.h"
#include "tlinklist.h"

using namespace std ;
int main ( void )
{

	zlinklist<student> ll;

	zlinklist<int> li;
	li.pushback(12);

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



