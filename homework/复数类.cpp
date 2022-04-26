#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class complex
{
public:
	complex();
	void set(float, float);
	friend complex operator+(const complex a, const complex b);
	friend complex operator-(const complex a, const complex b);
	friend complex operator*(const complex a, const complex b);
	friend complex operator/(const complex a, const complex b);
	friend ostream& operator<<(ostream& output, const complex a);
	friend istream& operator>>(istream& input, complex& a);
private:
	float real;
	float imag;
};
complex::complex()
{
	real = 0;
	imag = 0;
}
void complex::set(float x, float y)
{
	real = x;
	imag = y;
}
complex operator+(const complex a, const complex b)
{
	complex c;
	c.set(a.real + b.real,a.imag + b.imag);
	return c;
}
complex operator-(const complex a, const complex b)
{
	complex c;
	c.set(a.real - b.real, a.imag - b.imag);
	return c;
}
complex operator*(const complex a, const complex b)
{
	complex c;
	c.set(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
	return c;
}
complex operator/(const complex a, const complex b)
{
	complex c;
	int dem = b.real * b.real + b.imag * b.imag;
	c.set((a.real * b.real + a.imag * b.imag)/dem, (a.imag * b.real - a.real * b.imag)/dem);
	return c;
}
ostream& operator<<(ostream& output, const complex a)
{
	if (a.real == 0 && a.imag == 0)
	{
		output << 0;
		return output;
	}
	else if (a.real == 0)
	{
		output << a.imag << "i";
		return output;
	}
	else if (a.imag == 0)
	{
		output << a.real;
		return output;
	}
	if (a.imag < 0)
	{
		output << a.real << a.imag << "i";
		return output;
	}
	output << a.real << "+" << a.imag << "i";
	return output;
}
istream& operator>>(istream& input, complex& a)
{
	input >> a.real >> a.imag;
	return input;
}
int main()
{
	complex a, b, c;
	cout << "输入两个复数(格式： 实部 虚部)" << endl;
	cin >> a;
	cin >> b;
	cout << "加法" << endl;
	c = a + b;
	cout << c << endl;
	cout << "减法" << endl;
	c = a - b;
	cout << c << endl;
	cout << "乘法" << endl;
	c = a * b;
	cout << c << endl;
	cout << "除法" << endl;
	c = a / b;
	cout << c << endl;
	return 0;
}