#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}
	
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	/*Date(Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}*/

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void print() const 
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	Date& operator=(const Date& d);
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;

	Date& operator++();//前置
	Date operator++(int);//后置
	Date& operator--();
	Date operator--(int);
	//d1-d2
	int operator-(const Date d) const;
	//<<和>>重载一般不写成员函数
	//因为this默认抢了第一个参数位置，Dare对象就是左操作数，不符合使用习惯和可读性
	/*void operator<<(ostream& out)
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}*/

	Date* operator&()
	{
		return this;
	}
	const Date* operator&() const
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		_capacity = capacity;
		_top = 0;
	}
	Stack(const Stack& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
		memcpy(_a, st._a, sizeof(int) * st._top);//深拷贝
		_capacity = st._capacity;
		_top = st._top;
	}
	void Push(int x)
	{
		_a[_top] = x;
		_top++;
	}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _capacity;
	int _top;
};

class MyQueue
{
public:
	void push(int x)
	{
		_pushST.Push(x);
	}
private:
	Stack _pushST;
	Stack _popSt;
	size_t _size = 0;

};