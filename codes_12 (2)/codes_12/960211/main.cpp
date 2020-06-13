#include <QTextStream>
QTextStream qout (stdout) ;

#include <iostream>

#include <vector>
#include <QVector>

namespace bashari
{
	class xyz
	{
		public:
			enum wd
			{
				sha = 100,
				yek, 	dos,			ses ,			cha ,			pan,
				jom
			};
			class abc
			{
				public:
					int a ;
					void f ()
					{
						qout << "hello" << endl ;
					}
					enum bbb
					{
						far, 					ord,					khor
					};
			};
	};

}

namespace mohammad
{
	class xyz
	{
		public:
			enum wd
			{
				sha = 100,
				yek, 	dos,			ses ,			cha ,			pan,
				jom
			};
			class abc
			{
				public:
					int a ;
					void f ()
					{
						qout << "hello" << endl ;
					}
					enum bbb
					{
						far, 					ord,					khor
					};
			};
	};

}


namespace bashari {
	class alef
	{
			int alaki ;
	};
}
int a = 20 ;
int main ( void )
{
	int a = 10 ;
	qout << a << endl ;
	qout << ::a << endl ;
	qout << mohammad::xyz::wd::cha << endl ;

	bashari::xyz::wd x ;

	x = bashari::xyz::ses ;
	qout << x << endl ;

	using namespace bashari ;
	xyz::abc::bbb z ;

//	for ( xyz::wd dd = xyz::sha ; dd <= xyz:: jom ; dd = dd + 1  )
//	{
//		qout << dd << endl ;
//	}
	if ( xyz::jom + 1 == xyz::sha )
	{
		qout << "hoora" << endl ;
	}
	else
		qout << "wow" << endl ;

	xyz::wd ddd ;
	ddd = xyz::ses ;

	ddd = xyz::wd(200000) ;
	qout << double(ddd) ;

	using namespace std;

	vector<int> vi (10) ;

	for(int i = 0 ; i  < vi.size() ; i ++ )
		vi[i] = 2 * i ;

	for ( int i = 0 ; i < vi.size() ; i ++ )
		qout<< vi[i] << endl ;

	vi.resize(20);

	for ( int i = 0 ; i < vi.size() ; i ++ )
		qout<< vi[i] << endl ;

	qout << "____________________" << endl ;
	vi.resize(5);
	for ( int i = 0 ; i < vi.size() ; i ++ )
		qout<< vi[i] << endl ;

	qout << "____________________" << endl ;

	for ( int i = 0 ; i < vi.size() ; i ++ )
		qout<< vi.at(i) << endl ;

	qout << "____________________" << endl ;
	for (auto itr = vi.begin() ; itr != vi.end() ; ++ itr )
		qout << * itr << endl ;

	typedef vector<int>::iterator myitr ;

	qout << "____________________" << endl ;
	for ( myitr itr = vi.begin() ; itr != vi.end() ; ++ itr )
		qout << * itr << endl ;


	qout << "____________________" << endl ;
	for (int i = 0 ; i < 4 ; i ++ )
		vi.push_back(i*3);

	qout << "____________________" << endl ;
	for (auto itr = vi.begin() ; itr != vi.end() ; ++ itr )
		qout << * itr << endl ;


	qout << "____________________" << endl ;

	vector<int> qvi ;
	qvi.resize(100000000);
	qout << qvi.size() << endl ;
	for ( int i = 0 ; i < 100000000 ; i ++ )
		qvi.push_back(i*4);

	qout << "________hoora____________" << endl ;


	typedef int myint ;


	myint zz ;

	typedef bashari::xyz::abc mabc;
	mabc abcd ;


}
