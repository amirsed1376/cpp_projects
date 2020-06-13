#include <iostream>
#include <string.h>
using namespace std ;
struct student
{
	char name [20] ;
	double avg ;
	char addr [40] ;
};

struct node
{
	student data ;
	node * next ;
};

struct linklist
{
	node * head ;
};

void linklist_init ( linklist * that )
{
	that->head = nullptr ;
}

void linklist_add ( linklist * that  , student d )
{
	node * p ;
	p = new node ;
	p->data = x;
	p->next = that->head ;
	that->head = p ;
}


int main ( void )
{
	linklist a ;
	linklist_init( &a);

	while ( true )
	{
		cout << " continue " << endl ;
		char ans [10] ;
		cin >> ans ;
		if ( strcmp ( ans , "no") == 0 )
			break ;

		student x;
		cin >> x.name ;
		cin >> x.avg;
		cin >> x.addr ;

		linklist_add(&a ,x);
	}

	return 0 ;
}
