#define _CRT_SECURE_NO_WARNINGS 

#include "test.h"

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;
	while (_day < 0)
	{
		_day += GetMonthDay(_year, _month - 1);
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 13;
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date dat(*this);
	_day -= day;
	return dat;
}

bool Date::operator==(const Date& d)
{
	return d._year == _year
		&& d._month == _month
		&& d._day == _day;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}

	return false;
}
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

//«∞÷√
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//∫Û÷√
Date& Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}