#include <string.h>
#include <iostream>
using namespace std ;

class student
{
public :
	char name [ 100 ] ;
	float avg ;
	char addr [ 200] ;
	void chap ()
	{
		cout << "__________________" << endl ;
		cout << name << endl ;
		cout << avg << endl ;
		cout << addr << endl ;
	}
};


class node
{
public :
	student data ;
	node * next ;
};
class linklist
{
public :
	node * head ;
	node * tail ;
	void init ( )
	{
		head = nullptr ;
		tail = nullptr ;
	}
	void pushfront (  student z)
	{
		node * p = new node ;
		p->data = z;
		p->next = head ;
		head = p ;
		if ( tail == nullptr )
			tail = p ;
	}
void pushback ( student z )
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
void destroy ( )
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
};


int main ( void )
{
	linklist ll ;
	ll.init();


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

	node * tmp = ll.head ;
	while (tmp!=nullptr)
	{
		tmp->data.chap();
		tmp = tmp->next ;
	}

	ll.destroy();

}




//#include <string.h>
//#include <iostream>
//using namespace std ;

//struct student
//{
//	char name [ 100 ] ;
//	float avg ;
//	char addr [ 200] ;
//};

//void student_chap ( student * that )
//{
//	cout << "__________________" << endl ;
//	cout << that->name << endl ;
//	cout << that->avg << endl ;
//	cout << that->addr << endl ;
//}

//struct node
//{
//	student data ;
//	node * next ;
//};
//struct linklist
//{
//	node * head ;
//	node * tail ;
//};
//void linklist_init ( linklist  * that )
//{
//	that->head = nullptr ;
//	that->tail = nullptr ;
//}
//void linklist_pushfront ( linklist * that , student z)
//{
//	node * p = new node ;
//	p->data = z;
//	p->next = that->head ;
//	that->head = p ;
//	if ( that->tail == nullptr )
//		that->tail = p ;
//}
//void linklist_pushback (linklist * that , student z )
//{
//	if ( that->head == nullptr )
//	{
//		linklist_pushfront(that,z);
//		return ;
//	}

//	node * tmp = new node ;
//	tmp->data = z ;
//	tmp->next = nullptr ;

//	that->tail->next = tmp ;

//	that->tail = tmp ;
//}

//void linklist_destroy (linklist * that )
//{
//	node * tmp  ;
//	tmp = that->head ;
//	while ( tmp != nullptr )
//	{
//		node * tmp2 ;
//		tmp2 = tmp->next ;

//		delete tmp ;
//		tmp = tmp2 ;
//	}
//	that->head = nullptr ;
//	that->tail = nullptr;

//}

//int main ( void )
//{
//	linklist ll ;
//	linklist_init( &ll);


//	linklist ll2 ;
//	linklist_init( &ll2);

//	char ans [10] ;

//	while ( true )
//	{
//		cout << "continue? ";
//		cin >>ans ;
//		if ( strcmp(ans,"no") ==0 )
//			break ;

//		student x;
//		cin >> x.name ;
//		cin>>x.avg ;
//		cin>>x.addr ;

//		linklist_pushback(&ll,x);

//	}
//	cout << " end" << endl ;

//	node * tmp = ll.head ;
//	while (tmp!=nullptr)
//	{
//		student_chap(&tmp->data);
//		tmp = tmp->next ;
//	}

//	linklist_destroy(&ll);
//}


