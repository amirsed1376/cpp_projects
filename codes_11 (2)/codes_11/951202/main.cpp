#include <string.h>
#include <iostream>
#include "linklist.h"

using namespace std ;

void swap ( int * a , int * b )
{
	int t = * a;
	* a = * b ;
	* b = t ;
}
void mswap ( int & a , int & b )
{
	int t =  a;
	 a =  b ;
	 b = t ;
}
int main ( void )
{
	int x = 10 ;
	int y = 20 ;
	cout << x << " " << y <<endl;
	swap (&x,&y) ;
	cout << x << " " << y <<endl;
	mswap(x,y);
	cout << x << " " << y <<endl;

	int z ;
	z = 18 ;

	int & r = z;
	r = 19 ;
	cout << &r << endl ;
//	&r

	cout << z << endl ;

	int * rr = &z ;
	*rr = 20 ;
	cout << &rr << endl ;
//	&*rr

	cout << z << endl ;

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

		//		x.chap();

		ll.pushback(x);

	}
	cout << " end" << endl ;

//	node * tmp = ll.head ;
//	while (tmp!=nullptr)
//	{
//		tmp->data.chap();
//		tmp = tmp->next ;
//	}
}



