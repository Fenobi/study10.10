#define _CRT_SECURE_NO_WARNINGS 

#include "test.h"


int main()
{
	Date d1(2022,10,10);
	Date d2(d1);
	Date d3;
	//d1.print();
	//d2.print();
	d3.print();
	d3 = d1;
	d3.print();
	return 0;
}