// written by mahdi
// sample of operator overloading for student class

#include<iostream>
#include<string>
using namespace std;

class student
{
	string name;
	string fname;
	string major;
	int age;
	int stdno;
public:
	student() : name(""),fname(""),major(""),age(0),stdno(0)
	{
	}

	student(string t_name, string t_fname, string t_major, int t_age, int t_stdno)
	{
		name = t_name;
		fname = t_fname;
		major = t_major;
		age = t_age;
		stdno = t_stdno;
	}

	string get_name()
	{
		return name;
	}
	
	void set_name(string t_name)
	{
		name = t_name;
	}

	string get_fname()
	{
		return fname;
	}
	void set_fname(string t_fname)
	{
		fname = t_fname;
	}


	 int get_age()
	 {
		 return age;
	 }

	 void set_age(int t_age)
	 {
		 age = t_age;
	 }

	 void operator--()  //overload inside the class
	{
		this->age--;//just a sample ...
	}

};

void operator++(student& s) // overloading outside the class
{
	s.set_age(s.get_age() + 1);
}

istream& operator >> (istream& in, student& s) 
{
	string new_name, new_fname;
	cout << "enter new name : ";
	cin >> new_name;
	s.set_name(new_name);
	cout << "enter new family name : ";
	cin >> new_fname;
	s.set_fname(new_fname);

	return in;
}

ostream& operator<<(ostream& out , student& s)
{
	cout << "\n********\n";
	cout << "name : " << s.get_name() << endl << "family : " << s.get_fname() << endl << "age : " << s.get_age() << endl; //just a sample
	cout << "\n********\n";
	return out;
}

// U can also overload << operator like this:
//void operator<<(ostream& out,student& s)
//{
//	cout << s.get_name() << endl;
//	//and so on
//}
// BUT in this case you can not use this operator like this :
// student a,b;
// cout<<a<<b;
// you can just use it this way!:
// cout<<a;


int main()
{
	student a("mahdi", "salmanzadeh", "IT", 19, 9436);
	cout << a << endl;
	cin >> a;
	cout << a << endl;
	++a;
	cout << a << endl;
	--a;
	cout << a << endl;
	return 0;
}