#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	// 拷贝构造函数
	Date(const Date& d);

	// 赋值运算符重载
	Date& operator=(const Date& d);

	// 析构函数
	~Date();

	// 日期+=天数
	Date& operator+=(int day);

	// 日期+天数
	Date operator+(int day);

	// 日期-天数
	Date operator-(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d) const;

	// ==运算符重载
	bool operator==(const Date& d) const;

	// >=运算符重载
	bool operator >= (const Date& d) const;

	// <运算符重载
	bool operator < (const Date& d) const;

	// <=运算符重载
	bool operator <= (const Date& d) const;

	// !=运算符重载
	bool operator != (const Date& d) const;

	// 日期-日期 返回天数
	int operator-(const Date& d) const;

	int daysofyear()
	{
		Date tmp(_year, 1, 0);
		return *this - tmp;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << ":" << d._month << ":" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}


// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return months[month];
	}
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// 拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 赋值运算符重载
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// 析构函数
Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_day += GetMonthDay(_year, _month - 1);
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d) const
{
	if ((_year > d._year) || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ==运算符重载
bool Date::operator==(const Date& d) const
{
	if (_year == d._year && _month == d._month && _day == d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// >=运算符重载
bool Date::operator >= (const Date& d) const
{
	return (*this > d || *this == d);
}

// <运算符重载
bool Date::operator < (const Date& d) const
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d) const
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d) const
{
	return !(*this == d);
}

// 日期-日期 返回天数
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int n = 0;
	if (max < min)
	{
		max = d;
		min = *this;
	}
	while (min != max)
	{
		min++;
		n++;
	}
	return n;
}

int main() {
	Date a;
	cin >> a;
	cout << a.daysofyear() << endl;
}
// 64 位输出请用 printf("%lld")