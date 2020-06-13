#include <iostream>
#include <fstream>
#include <string.h>

#define slen 17
#define begin {
#define end }
#define karbarfile "d:\\karbaran.txt"


using namespace std;
void jabeja ( char * x , char * y )
begin
	char t [slen] ;
	strcpy ( t , x ) ; // t = x ;
	strcpy ( x, y ) ;  // x = y ;
	strcpy ( y , t ) ;  // y = t
end

void cpy (char * s , char * d )
begin
	ifstream src ( s ) ;
	ofstream dst ( d ) ;
	while ( !src.eof())
	{
		char c [ 100 ];
		src >> c ;
		dst << c << " " ;
	}
	src.close();
	dst.close() ;
end
void hazf ()
{
	cpy ( karbarfile, "d:\\karbarancopy.txt");
	char famil_t [ slen ] ;
	cout << " famil karbar ra vared konid " << endl ;
	cin >> famil_t ;
	ifstream karbar ("d:\\karbarancopy.txt") ;
	ofstream karbar_o (karbarfile) ;
	while ( !karbar.eof() )
	begin
		char name [slen] ;
		char famil [ slen ] ;
		char shomare [ slen ] ;
		karbar >> name >> famil >> shomare ;
		if ( !strstr (famil,famil_t) )
			karbar_o << name << " " << famil << " " << shomare << endl ;
	end
	karbar.close();
	karbar_o.close();
}
void list ()
{
	ifstream karbar (karbarfile) ;
	while ( !karbar.eof() )
	{
		char name [slen] ;
		char famil [ slen ] ;
		char shomare [ slen ] ;
		name[0] = 0 ;
		karbar >> name >> famil >> shomare ;
		if (name[0]!=0)
			cout << name << "\t" << famil << "\t" << shomare << endl ;
	}
	karbar.close();
}
void help ()
{
	cout << "een barnameye ketabkhane ast " <<endl ;
	cout << "k\tkhorooj" << endl ;
	cout << "a\tafzoodane karbar" << endl ;
	cout << "j\tjostojooye karbar" << endl ;
	cout << "h\tkomak" << endl ;
	cout << "l\tlist" << endl ;
	cout << "z\thazf" << endl ;
	cout << "s\tsort" << endl ;
}

int mcmp ( char * x , char * y )
{
	int i = 0 ;
	while ( true )
	{
		if ( x[i] < y[i])
			return -1;
		if ( x [i] > y [i] )
			return 1 ;
		if ( x[i] == 0 && y [i] == 0 )
			return 0 ;
		i ++ ;
	}
}

void jostojooye_karbar ()
{
	char famil_t [ slen ] ;
	cout << " famil karbar ra vared konid " << endl ;
	cin >> famil_t ;
	ifstream karbar (karbarfile) ;
	while ( !karbar.eof() )
	{
		char name [slen] ;
		char famil [ slen ] ;
		char shomare [ slen ] ;
		name[0] = 0 ;
		karbar >> name >> famil >> shomare ;
		if ( strstr (famil,famil_t) )
		{
			cout << name << " " << famil << " " << shomare << endl ;
		}
	}
	karbar.close();
}

void afzoodane_karbar ()
{
	char name [slen] ;
	char famil [ slen ] ;
	char shomare [ slen ] ;
	cout << " name karbar ra vared konid " << endl ;
	cin >> name ;
	cout << " famil karbar ra vared konid " << endl ;
	cin >> famil ;
	cout << " shomare karbar ra vared konid " << endl ;
	cin >> shomare ;

	ofstream karbar (karbarfile, ios::app ) ;
	karbar << name << " " << famil << " " << shomare << endl ;
	karbar.close();
}

void sort ()
{
	char namha [600][slen];
	char familha [600][slen];
	char shomareha [600][slen];
	int i = 0 ;
	{
		ifstream karbar (karbarfile) ;
		while ( !karbar.eof() )
		{
			namha[i][0] = 0 ;
			karbar >> namha[i] >> familha[i] >> shomareha[i] ;
			if (namha[i][0]!=0)
				i ++ ;
		}
		karbar.close();
	}

	for ( int j = 0 ; j < i - 1 ; j ++ )
		for ( int k = j + 1  ; k < i ; k ++  )
			if ( strcmp (familha[j],familha[k]) > 0 )
			{
				// bayad jabeja konam
				jabeja(familha[j],familha[k]);
				jabeja(namha[j],namha[k]);
				jabeja(shomareha[j],shomareha[k]);
			}

	{
		ofstream karbar ( karbarfile ) ;
		for ( int j = 0 ; j < i ; j ++ )
			karbar << namha[j] << " " << familha[j] << ' ' << shomareha [j] << endl ;
		karbar.close();
	}
}

int main ( void )
{
	help () ;
	while ( true )
	{
		cout << "________________________________________-" <<endl  ;
		cout << " dastoor vared konid " <<endl  ;
		char c ;
		cin >> c ;
		system ( "cls") ;
		if( c == 'k')
			return 0 ;
		else if ( c == 'a')
			afzoodane_karbar () ;
		else if ( c == 'j')
			jostojooye_karbar () ;
		else if ( c == 'h')
			help () ;
		else if ( c == 'l')
			list () ;
		else if ( c == 'z')
			hazf () ;
		else if ( c == 's')
			sort () ;
		else
			help () ;
	}
}

