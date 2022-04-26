#include <iostream>
#include <cmath>
using namespace std;
class Rational
{
public:
	Rational();
	void set(int,int);//设置分子分母
	friend Rational operator+(const Rational& a, const Rational& b);//加号重载
	friend Rational operator-(Rational& a,  Rational& b);//减号重载
	friend Rational operator*(const Rational& a, const Rational& b);//乘号重载
	friend Rational operator/(const Rational& a, const Rational& b);//除号重载
	friend ostream& operator<<(ostream& output,Rational& a);//输出流重载
	friend istream& operator>>(istream& intput,Rational& a);//输入流重载
private:
	int numerator;//分子
	int denominator;//分母
};
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}
void Rational::set(int x, int y)//设置分子分母
{
	numerator = x;
	denominator = y;
}
Rational operator+(const Rational& a, const Rational& b)
{
	Rational c;
	if (a.denominator == 0 || b.denominator == 0)
	{
		c.set(0, 0);
		return c;
	}
	else if (a.numerator == 0)
	{
		return b;
	}
	else if (b.numerator == 0)
	{
		return a;
	}
	c.set(a.numerator + b.numerator,a.denominator + b.denominator);
	return c;
}
Rational operator-( Rational& a, Rational& b)
{
	Rational c;
	if (a.denominator == 0 || b.denominator == 0)
	{
		c.set(0, 0);
		return c;
	}
	else if (a.numerator == 0)
	{
		b.numerator = -(b.numerator);
		return b;
	}
	else if (b.numerator == 0)
	{
		return a;
	}
	c.set(a.numerator - b.numerator,a.denominator - b.denominator);
	return c;
}
Rational operator*(const Rational& a, const Rational& b)
{
	Rational c;
	if (a.denominator == 0 || b.denominator == 0)
	{
		c.set(0, 0);
		return c;
	}
	else if (a.numerator == 0 || b.numerator == 0)
	{
		c.set(0, 1);
		return c;
	}
	c.set(a.numerator * b.numerator,a.denominator * b.denominator);
	return c;
}
Rational operator/(const Rational& a, const Rational& b)
{
	Rational c;
	if (a.denominator == 0 || b.numerator == 0)
	{
		c.set(0, 0);
		return c;
	}
	else if (a.numerator == 0 || b.denominator == 0)
	{
		c.set(0, 1);
		return c;
	}
	c.set(a.numerator * b.denominator,a.denominator * b.numerator);
	return c;
}
ostream& operator<<(ostream& output,Rational& a)
{
	if (a.denominator == 0)//分母为0时
	{
		output << "无穷大";
		return output;
	}
	else if(a.numerator == 0)//分子为0时
	{
		output << "0";
		return output;
	}
	else
	{
		if (a.denominator * a.numerator > 0)//分子分母同号
		{
			output << abs(a.numerator) << "/" << abs(a.denominator);
		}
		else//异号
		{
			output << "-" << abs(a.numerator) << "/" << abs(a.denominator);
		}
		return output;
	}
}
istream& operator>>(istream& intput,Rational& a)
{
	intput >> a.numerator >> a.denominator;
	return intput;
}


int main()
{
	Rational a, b, s;
	cout << "输入两个分数(格式：分子 分母)" << endl;
	cin >> a;
	cin >> b;
	s = a + b;
	cout << " a + b = " << s << endl;
	s = a - b;
	cout << " a - b = " << s << endl;
	s = a * b;
	cout << " a * b = " << s << endl;
	s = a / b;
	cout << " a / b = " << s << endl;
	return 0;
}