#include "z_theapp.h"
#include <QPushButton>

#include <QThread>
#include <iostream>
#include <mutex>
#include <QMutex>

#include <QSharedPointer>

using namespace std ;

int cnt = 0 ;
mutex my_mutex;
class z_test
{
	public :
		int i ;
		z_test()
		{
			cout << "ctor" << endl;
		}
		~z_test()
		{
			cout << "dtor" << endl ;
		}
};

class z_mythread : public QThread
{
	public :
		int del ;
	z_mythread (int delay) : del ( delay ) {}

	void run ()
	{
		int a = 0 ;
		while (true)
		{
			QSharedPointer<z_test> test (new z_test);

//			test = QSharedPointer<z_test>( new z_test )  ;
			test->i ++ ;
			cout << "(" <<test-> i <<endl ;


//			z_test test ;

			my_mutex.lock();
			cout << a ++ << '\t' ;
			my_mutex.unlock();
			msleep(del);
//			my_mutex.lock();
//			cnt ++ ;
//			my_mutex.unlock();

//			my_mutex.lock();
//			cnt -- ;
//			my_mutex.unlock();
		}
	}
};


int main(int argc, char *argv[])
{


	{
	}

	z_mythread thread (1000);
	thread.start();

	z_mythread th2(1000) ;
	th2.start();

//	for ( int i = 0 ; i < 10 ; i ++ )
//	{
//		z_mythread * th = new z_mythread;
//		th->start();
//	}
	z_theapp theapp(argc, argv);
	return theapp.exec();
}
