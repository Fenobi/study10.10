#define _CRT_SECURE_NO_WARNINGS 

#include "test.h"

void test1()
{
	Date d1;
	Date d2(d1);
	Date d3;
	//d1.print();
	//d2.print();
	d3.print();
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
	d1--;
	d1.print();
	--d1;
	d1.print();
	(++d1);
	d1.print();
	(d1++);
	d1.print();

}

void test4()
{
	Date d1(2022, 10, 9);
	Date d2(2022, 10, 9);
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
}

void test5()
{
	Date d1(2022, 10, 12);
	Date d2(2023, 9, 1);//秋招
	Date d3(2023, 7, 1);//提前批
	Date d4(2023, 3, 1);//实习
	cout << d2 - d1 << endl;
	cout << d3 - d1 << endl;

}

void menu()
{
	cout << "          日期计算器         " << endl;
	cout << "******************************" << endl;
	cout << "************1、开始***********" << endl;
	cout << "************0、结束***********" << endl;
	cout << "******************************" << endl;
}

void test6()
{
	int input=1;
	do
	{
		menu();
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "计算：>" << endl;
			break;
		case 0:
			cout << "结束" << endl;
			break;
		default:
			cout << "输入错误!" << endl;
			break;
		}
	} while (input);
}

void test7()
{
	Date d1(2022, 10, 13);
	Date d2(d1);
	cin >> d1 >> d2;
	cout << d1 << d2;
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}