#define _CRT_SECURE_NO_WARNINGS 

#include "test.h"

void test1()
{
	Date d1(2022, 10, 10);
	Date d2(d1);
	Date d3;
	//d1.print();
	//d2.print();
	d3.print();
	d3 = d1;//即使不写=，系统也会自动生成
	d3.print();
}

void test2()
{
	Date d1(2022, 10, 12);
	Date d2(d1);
	d2 += -1000;
	d2.print();
	d2 -= -1000;
	d2.print();
}

void test3()
{
	Date d1;
	d1++;
	d1.print();
	++d1;
	d1.print();
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}