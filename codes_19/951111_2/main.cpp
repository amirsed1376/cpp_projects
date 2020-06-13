#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define num 10
struct student
{
	char name [50] ;
	double avg ;
	char famil [40] ;
};

int main ( void )
{
	srand (time(0)) ;
	char name [num][50] ;
	double avg [num] ;
	char famil [num][40] ;

	student s [num] ;

	for ( int i = 0 ; i < num ; i ++ )
	{
		int len = rand () % 20 + 1 ;
		for ( int j = 0 ; j < len ; j ++ )
			name [i][j] = rand () % 26 + 'A' ;
		name [ i][len] = 0 ;
	}

	for ( int i = 0 ; i < num ; i ++ )
		cout << name[i] << endl ;

	cout << "__________________________________________" << endl ;

	for ( int i = 0 ; i < num ; i ++ )
	{
		int len = rand () % 20 + 1 ;
		for ( int j = 0 ; j < len ; j ++ )
			s[i]. name [j] = rand () % 26 + 'A' ;
		s[i].name[len] = 0 ;
	}

	for ( int i = 0 ; i < num ; i ++ )
		cout << s[i].name << endl ;

	cout << "__________________________________________" << endl ;

	student * p ;


	p = & s[2] ;

	(*p).avg = 18 ;

	p->avg = 19 ;

	p = s ;


	for ( int i = 0 ; i < num ; i ++ )
	{
		int len = rand () % 20 + 1 ;
		for ( int j = 0 ; j < len ; j ++ )
			p[i]. name [j] = rand () % 26 + 'A' ;
		p[i].name[len] = 0 ;
	}

	for ( int i = 0 ; i < num ; i ++ )
		cout << p[i].name << endl ;

	return 0 ;
}
