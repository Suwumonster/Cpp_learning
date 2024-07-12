#pragma once
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
namespace my_stl
{
	template<class T, class Container = vector<T>, class compare = less<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (compare()(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
				}
				else
				{
					break;
				}
				child = parent;
				parent = (child - 1) / 2;
			}
		}

		void adjust_down(size_t parent)
		{
			size_t child = 2 * parent + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && compare()(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (compare()(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
				}
				else
				{
					break;
				}
				parent = child;
				child = 2 * parent + 1;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		T top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}
