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
	//功能：删除数据、初始化无效数据、初始化无效数据前扩容
	void string::resize(size_t n, char ch)
	{
		//< _size 删除数据
		if (n <= _size)
		{
			_size = n;
			_str[_size] = '\0';
		}
		else
		{
			if (n > _capacity)
			{
				reserve(n);
			}

			size_t i = _size;
			while (i < n)
			{
				_str[i] = ch;
				i++;
			}
			_size = n;
			_str[_size] = '\0';
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
	string& string::operator+=(char c)
	{
		push_back(c);
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


	//挪动数据 逆向挪动  因为 _size 等成员变量都是 size_t 所以参数也是 size_t 类型
	void move(char* str, size_t srcH, size_t dstH, size_t moveStrLen)
	{
		if (str == nullptr)
		{
			return;
		}
		size_t i = 0;
		//这里循环比较特别是因为 size_t 类型 如果==0 再-- 就会变成最大无符号整数  从而无限循环
		for (i = moveStrLen; i > 0; i--)
		{
			str[dstH + i - 1] = str[srcH + i - 1];
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
		int maxEarseLen = _size - pos;// 这里多一个变量可以避免数据溢出
		// if(len == npos || _size < len + pos)
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

	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}


	size_t string::size()const
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}
	bool string::empty()const
	{
		return _size == 0;
	}

	std::ostream& operator<<(std::ostream& out, const my_stl::string& s)
	{
		size_t i = 0;
		size_t size = s.size();
		while (i < size)
		{
			out << s[i];
			i++;
		}
		return out;
	}
	std::istream& operator>>(std::istream& in, my_stl::string& s)
	{
		s.clear();
		char buff[128] = { 0 };
		int i = 0;
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i] = ch;
			i++;
			if (i == 127)//127就存储\0 不会改变 避免刚好128字符没有\0的情况
			{
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			int j = 0;
			while (j < i)
			{
				s += buff[j];//底层是pushback 自己会在后面加\0
				j++;
			}
		}
		return in;
	}


	// 返回c在string中第一次出现的位置
	size_t string::find(char c, size_t pos) const
	{
		size_t i = pos;
		for (i = pos; i < _size; i++)
		{
			if (_str[i] == c)
			{
				return i;
			}
		}
		return npos;
	}

	// 返回子串s在string中第一次出现的位置
	size_t string::find(const char* s, size_t pos) const
	{
		char* tmp = strstr(_str, s);
		if (tmp == nullptr)
		{
			return npos;
		}
		return tmp - _str;
	}
}