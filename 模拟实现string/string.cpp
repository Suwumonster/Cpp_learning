#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace my_stl
{
	char* string::c_str()
	{
		return _str;
	}
	const char* string::c_str() const
	{
		return _str;
	}

	char& string::operator[](size_t i)
	{
		return _str[i];
	}

	const char& string::operator[](size_t i) const
	{
		return _str[i];
	}

	string& string::operator=(const string& s)//需要考虑情况：1。new失败 保留旧数据 2。自身赋值的情况
	{
		char* tmp = new char[s._capacity + 1];
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
		return *this;
	}

	string& string::operator=(const char* s)//复用构造 赋值重载
	{
		string tmp(s);
		*this = tmp;
		return *this;
	}


	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}
	string::const_iterator string::begin() const
	{
		return _str;
	}
	string::const_iterator string::end() const
	{
		return _str + _size;
	}

	//主要负责扩容，处理容量capacity n表示str长度
	void string::reserve(size_t n)//记得new失败保留旧数据
	{
		if (_size < n)//根据stl reserve的定义只有n大于str的长度才进行reserve
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}


	void string::push_back(char ch)
	{
		if (_size + 1 > _capacity)//扩容
		{
			size_t newCapacity = _capacity == 0 ? 3 : 2 * _capacity;
			reserve(newCapacity);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}


	string& string::append(const char* s)
	{
		size_t newlen = strlen(s) + _size;
		reserve(newlen);
		strcpy(_str + _size, s);
		_size = newlen;
		return *this;
	}

	string& string::operator+=(const string& s)//复用append
	{
		append(s._str);
		return *this;
	}


	int string::operator<(const string& s)
	{
		return strcmp(_str, s._str);
	}
	int string::operator==(const string& s)
	{
		return strcmp(_str, s._str);
	}

	int string::operator<=(const string& s)
	{
		return ( *this < s || *this == s);
	}
	int string::operator!=(const string& s)
	{
		return !(*this == s);
	}

	int string::operator>(const string& s)
	{
		return !(*this <= s);
	}

	int string::operator>=(const string& s)
	{
		return !(*this < s);
	}

	string string::substr(size_t pos, size_t len) const
	{
		int sub_len = len == npos ? _size - pos: len;
		char* tmp = new char[sub_len + 1];
		int i = 0;
		for (i = 0; i < sub_len; i++)
		{
			tmp[i] = _str[pos + i];
		}
		tmp[i] = '\0';
		string s(tmp);
		delete[] tmp;
		return s;
	}

	void move(char* str, int srcH, int dstH, int moveStrLen)
	{
		if (str == nullptr)
		{
			return;
		}
		int i = 0;
		for (i = moveStrLen - 1; i >= 0; i--)
		{
			str[dstH + i] = str[srcH + i];
		}

	}

	string& string::insert(size_t pos, const char* str)
	{
		if (pos > _size)
		{
			throw "out of range";
		}
		int insert_len = strlen(str);//插入str的长度
		int moveStrLen = _size - pos;//原str需要move的长度
		size_t new_size = _size + insert_len;//插入后str的长度
		reserve(new_size);//扩容
		int i = 0;
		_str[new_size] = '\0';//先在末尾加上\0
		move(_str, pos, new_size - moveStrLen, moveStrLen);
		for (i = 0; i < insert_len; i++)
		{
			_str[pos + i] = str[i];
		}
		_size = new_size;
		return *this;
	}
	string& string::erase(size_t pos, size_t len)
	{
		if (pos > _size - 1)
		{
			throw "out of range";
		}
		int maxEarseLen = _size - pos;
		if (maxEarseLen < len)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			int i = 0;
			int moveStrLen = _size - len - pos;
			for (i = 0; i < moveStrLen; i++)
			{
				_str[i + pos] = _str[pos + len + i];
			}
			_str[i + pos] = '\0';
		}
		return *this;
	}
}