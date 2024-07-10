#pragma once
#include <vector>
#include <list>
#include <utility>
#include <iostream>
using namespace std;

namespace my_stl
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_back();
		}
		T top()
		{
			return con.back();
		}
		bool empty()
		{
			return con.empty();
		}
		size_t size()
		{
			return con.size();
		}
		void swap(stack<T, Container>& c)
		{
			std::swap(con, c.con);
		}
	private:
		Container con;
	};

	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_front();
		}
		T front()
		{
			return con.front();
		}
		T back()
		{
			return con.back();
		}
		bool empty()
		{
			return con.empty();
		}
		size_t size()
		{
			return con.size();
		}
		void swap(queue<T, Container>& c)
		{
			std::swap(con, c.con);
		}
	private:
		Container con;
	};
}
