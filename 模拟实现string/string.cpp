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

	string& string::operator=(const string& s)//��Ҫ���������1��newʧ�� ���������� 2������ֵ�����
	{
		char* tmp = new char[s._capacity + 1];
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
		return *this;
	}

	string& string::operator=(const char* s)//���ù��� ��ֵ����
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

	//��Ҫ�������ݣ���������capacity n��ʾstr����
	void string::reserve(size_t n)//�ǵ�newʧ�ܱ���������
	{
		if (_size < n)//����stl reserve�Ķ���ֻ��n����str�ĳ��ȲŽ���reserve
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	//���ܣ�ɾ�����ݡ���ʼ����Ч���ݡ���ʼ����Ч����ǰ����
	void string::resize(size_t n, char ch)
	{
		//< _size ɾ������
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
		if (_size + 1 > _capacity)//����
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

	string& string::operator+=(const string& s)//����append
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


	//Ų������ ����Ų��  ��Ϊ _size �ȳ�Ա�������� size_t ���Բ���Ҳ�� size_t ����
	void move(char* str, size_t srcH, size_t dstH, size_t moveStrLen)
	{
		if (str == nullptr)
		{
			return;
		}
		size_t i = 0;
		//����ѭ���Ƚ��ر�����Ϊ size_t ���� ���==0 ��-- �ͻ�������޷�������  �Ӷ�����ѭ��
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
		int insert_len = strlen(str);//����str�ĳ���
		int moveStrLen = _size - pos;//ԭstr��Ҫmove�ĳ���
		size_t new_size = _size + insert_len;//�����str�ĳ���
		reserve(new_size);//����
		int i = 0;
		_str[new_size] = '\0';//����ĩβ����\0
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
		int maxEarseLen = _size - pos;// �����һ���������Ա����������
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
			if (i == 127)//127�ʹ洢\0 ����ı� ����պ�128�ַ�û��\0�����
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
				s += buff[j];//�ײ���pushback �Լ����ں����\0
				j++;
			}
		}
		return in;
	}


	// ����c��string�е�һ�γ��ֵ�λ��
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

	// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
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