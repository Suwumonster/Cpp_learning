#pragma once

namespace my_stl
{
	template<class Iterator, class Ref, class Ptr>
	class Reverse_Iterator
	{
	public:
		typedef Reverse_Iterator<Iterator, Ref, Ptr> Self;
		Reverse_Iterator(Iterator it):_cur(it){}
		Ref operator*()//important!!!
		{
			Iterator tmp = _cur;
			--tmp;
			return *tmp;
		}
		Ptr operator->()
		{
			Iterator tmp = _cur;
			--tmp;
			return tmp.operator->();
		}
		Self& operator++()
		{
			_cur--;
			return *this;
		}
		Self& operator++(int)
		{
			Self tmp = *this;
			_cur--;
			return tmp;
		}
		Self& operator--()
		{
			_cur++;
			return *this;
		}

		Self& operator--(int)
		{
			Self tmp = *this;
			_cur++;
			return tmp;
		}
		bool operator==(const Self& s)
		{
			return _cur == s._cur;
		}
		bool operator!=(const Self& s)
		{
			return _cur != s._cur;
		}
	private:
		Iterator _cur;
	};
}
