#include "student.h"
#include <iostream>

void student::chap()
{
	std::cout << " ================= " << std:: endl ;
	std::cout << name << std::endl ;
	std::cout << this->addr << std::endl ;
	std::cout << this->avg << std::endl ;
}
