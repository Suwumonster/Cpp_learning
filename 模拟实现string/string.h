#pragma once
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

namespace my_stl
{
	class string
	{
	public:
		//非const迭代器
		typedef char* iterator;
		iterator begin();
		iterator end();


		//const迭代器
		typedef const char* const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		//构造和析构

		string(const char* s = "")
		{
			_size = strlen(s);
			_capacity = _size;
			char* tmp = new char[_capacity + 1];//加上\0的存储空间
			_str = tmp;
			strcpy(_str, s);
		}
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}


		char* c_str();
		const char* c_str() const;//为了const对象也能使用

		char& operator[](size_t i);
		const char& operator[](size_t i) const;

		string& operator=(const string& s);
		string& operator=(const char* s);


		void reserve(size_t n);

		void push_back(char ch);

		string& append(const char* s);

		string& operator+=(const string& s);

		int operator<(const string& s);
		int operator==(const string& s);
		int operator<=(const string& s);
		int operator!=(const string& s);
		int operator>(const string& s);
		int operator>=(const string& s);

		string substr(size_t pos = 0, size_t len = npos) const;
		string& insert(size_t pos, const char* str);
		string& erase(size_t pos = 0, size_t len = npos);

	private:
		char* _str;
		size_t _size;//str长度
		size_t _capacity;//有效数据的容量 不包含\0 实际上_str的空间会比capacity多1
		static const size_t npos = -1;
	};
}
