#include <iostream>
using namespace std ;
#include "linklist.h"
void student::chap ()
{
	cout << "__________________" << endl ;
	cout << this->name << endl ;
	cout << avg << endl ;
	cout << addr << endl ;
}
void linklist::pushfront (  student z)
{
	node * p = new node ;
	p->data = z;
	p->next = this->head ;
	head = p ;
	if ( tail == nullptr )
		tail = p ;
}
linklist::linklist () : head (nullptr), tail (nullptr)
{
}
void linklist::pushback ( student z )
{
	if ( head == nullptr )
	{
		pushfront(z);
		return ;
	}

	node * tmp = new node ;
	tmp->data = z ;
	tmp->next = nullptr ;

	this->tail->next = tmp ;

	this->tail = tmp ;
}
void linklist::destroy ( )
{
	node * tmp  ;
	tmp = this->head ;
	while ( tmp != nullptr )
	{
		node * tmp2 ;
		tmp2 = tmp->next ;

		delete tmp ;
		tmp = tmp2 ;
	}
	this->head = nullptr ;
	tail = nullptr;
}
linklist::~linklist()
{
	destroy();
}
