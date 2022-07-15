#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int compete(const string s)
{
	stack <int> st;
	stack <char> com;
	char in;
	for (int i = 0; i < s.size() ; i++)
	{
		in = s[i];
		if (in == ' ')//空格跳过
		{
			continue;
		}
		else if (in == 'V')//接收V
		{
			st.push(1);
		}
		else if (in == 'F')//接收F
		{
			st.push(0);
		}
		else if (in == ')' && !com.empty())//接收到)，开始运算
		{
			while (!com.empty())//运算符栈不空就算
			{
				char temp = com.top();
				com.pop();
				int x, y;
				if (temp == '(')//遇到（跳出循环
				{
					break;
				}
				else if (temp == '!')
				{
					x = st.top();
					st.pop();
					x = !x;
					st.push(x);
				}
				else if (temp == '&')
				{
					x = st.top();
					st.pop();
					y = st.top();
					st.pop();
					x = x && y;
					st.push(x);
				}
				else if (temp == '|')
				{
					x = st.top();
					st.pop();
					y = st.top();
					st.pop();
					x = x || y;
					st.push(x);
				}
			}
		}
		else if (in == '!')//接收到 !
		{
			if (s[i + 1] == 'V' || s[i + 1] == 'F')
			{
				int x = ((s[i + 1] == 'V') ? 1 : 0);
				x = !x;
				st.push(x);
				i++;
			}
			else
			{
				com.push(in);//将! 存入 com 栈中
			}
		}
		else if (in == '(')//接收到（
		{
			com.push(in);
		}
		else if (in == '&' || in == '|')//接收到 & 或 |
		{
			while (!com.empty() && com.top() == '!')//先将 非 运算符算完
			{
				com.pop();
				int x = st.top();
				st.pop();
				x = !x;
				st.push(x);
			}
			if (in == '&')// 接收到 &
			{
				if (!com.empty() && com.top() != '(')
				{
					char temp;
					temp = com.top();
					int x, y;
					if (temp == '&')
					{
						com.pop();
						x = st.top();
						st.pop();
						y = st.top();
						st.pop();
						x = x && y;
						st.push(x);
					}
				}
				com.push(in);//运算符栈空不空都需要将 & 存入 com 栈中
			}
			else if (in == '|')// 接收到 |
			{
				if (!com.empty() && com.top() != '(')
				{
					char temp;
					temp = com.top();
					com.pop();
					int x, y;
					if (temp == '&')
					{
						x = st.top();
						st.pop();
						y = st.top();
						st.pop();
						x = x && y;
						st.push(x);
					}
					else if (temp == '|')
					{
						x = st.top();
						st.pop();
						y = st.top();
						st.pop();
						x = x || y;
						st.push(x);
					}
				}
				com.push(in);//运算符栈空不空都需要将 | 存入 com 栈中
			}
		}
	}
	while (!com.empty())
	{
		char temp;
		temp = com.top();
		com.pop();
		int x, y;
		if (temp == '!')
		{
			x = st.top();
			st.pop();
			x = !x;
			st.push(x);
		}
		if (temp == '&')
		{
			x = st.top();
			st.pop();
			y = st.top();
			st.pop();
			x = x && y;
			st.push(x);
		}
		else if (temp == '|')
		{
			x = st.top();
			st.pop();
			y = st.top();
			st.pop();
			x = x || y;
			st.push(x);
		}
	}
	int x = st.top();
	st.pop();
	return x;
}
int main()
{
	string s;
	int i = 1;
	while (getline(cin, s))
	{
		int num = compete(s);
		if (num == 1)
		{
			cout << "Expression " << i++ << ": V" << endl;
		}
		else
		{
			cout << "Expression " << i++ << ": F" << endl;
		}
	}
	return 0;
}