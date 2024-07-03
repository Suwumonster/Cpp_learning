#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <utility>
#include <string>

namespace my_stl
{
	template<class T>
	class vector
	{
	public:
		//原生指针迭代器
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}

		//construct and destroy
		vector():_start(nullptr), _finish(nullptr), _outOfStorage(nullptr)
		{}
		vector(size_t n, const T& value = T())//reload vector
			:_start(nullptr), _finish(nullptr), _outOfStorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				*_finish = value;
				_finish++;
			}
		}
		vector(int n, const T& value = T())//reload vector
			:_start(nullptr), _finish(nullptr), _outOfStorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				*_finish = value;
				_finish++;
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr), _finish(nullptr), _outOfStorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)
			:_start(nullptr), _finish(nullptr), _outOfStorage(nullptr)
		{
			size_t sz = v.size();
			reserve(sz);
			for (int i = 0; i < sz; i++)
			{
				_start[i] = v._start[i];
			}
		}
		vector<T>& operator= (const vector<T>& v)
		{
			int sz = v.size();
			reserve(sz);
			for (int i = 0; i < sz; i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + sz;
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _outOfStorage = nullptr;
		}

		//capacity
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _outOfStorage - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//don't use memcpy, it cause copy problem.
					//memcpy(tmp, _start, sizeof(T) * sz);
					for (int i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + sz;
				_outOfStorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				//del data
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = value;
					_finish++;
				}
			}
		}


		//access
		T& operator[](size_t pos)
		{
			assert(pos + _start >= _start);
			assert(pos + _start < _finish);
			return *(_start + pos);
		}
		const T& operator[](size_t pos) const
		{
			assert(pos + _start >= _start);
			assert(pos + _start < _finish);
			return *(_start + pos);
		}

		//modify
		void push_back(const T& x)
		{
			if (size() + 1 > capacity())
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(_start != _finish);
			_finish--;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_outOfStorage, v._outOfStorage);
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (size() + 1 > capacity())
			{
				size_t posOffset = pos - _start;//remember pos offset, help don't loss pos
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + posOffset;
			}

			//move data
			iterator movePtr = end();
			while (movePtr != pos)
			{
				*(movePtr) = *(movePtr - 1);
				movePtr--;
			}

			//insert
			*pos = x;
			_finish++;

			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			//move data
			iterator movePtr = pos + 1;
			while (movePtr != end())
			{
				*(movePtr - 1) = *movePtr;
				movePtr++;
			}
			_finish--;
			return pos + 1;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _outOfStorage;
	};
}
