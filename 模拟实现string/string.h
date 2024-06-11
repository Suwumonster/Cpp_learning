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
		//��const������
		typedef char* iterator;
		iterator begin();
		iterator end();


		//const������
		typedef const char* const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		//���������

		string(const char* s = "")
		{
			_size = strlen(s);
			_capacity = _size;
			char* tmp = new char[_capacity + 1];//����\0�Ĵ洢�ռ�
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
		const char* c_str() const;//Ϊ��const����Ҳ��ʹ��

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
		size_t _size;//str����
		size_t _capacity;//��Ч���ݵ����� ������\0 ʵ����_str�Ŀռ���capacity��1
		static const size_t npos = -1;
	};
}
