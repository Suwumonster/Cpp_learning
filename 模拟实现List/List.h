#pragma once
#include <assert.h>
#include <utility>
#include "Reverse_Iterator.h"
//unknown reason List can't use funtion find in the algorithm 
//for convenient to find element in the list, so i define another find that i can use.

namespace my_stl
{
	template <class T>
	struct ListNode
	{
		T _data;
		ListNode* _prev;
		ListNode* _next;

		ListNode(T data = T()):_data(data), _prev(nullptr), _next(nullptr){}
		
	};

	template <class T, class Ref, class Ptr>
	struct Iterator
	{
		typedef Iterator<T, Ref, Ptr> self;
		typedef ListNode<T> Node;
		Node* node;
		Iterator(Node* n = nullptr): node(n){}
		Iterator(const self& l)
		{
			node = l.node;
		}
		self& operator++()
		{
			node = node->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp = *this;
			node = node->_next;
			return tmp;
		}
		self& operator--()
		{
			node = node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp = *this;
			node = node->_prev;
			return tmp;
		}

		bool operator!=(const self& tmp)
		{
			return node != tmp.node;
		}

		bool operator==(const self& tmp)
		{
			return node == tmp.node;
		}

		Ref operator*()
		{
			return node->_data;
		}

		Ptr operator->()
		{
			return &(node->_data);
		}
	};


	template <class T>
	class List
	{
	public:
		typedef ListNode<T> Node;

		//Iterators:
		typedef Iterator<T, T&, T*> iterator;
		typedef Iterator<T, const T&, const T*> const_iterator;
		typedef Reverse_Iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_Iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		//Construct and destroy
		List()
		{
			_head = NewNode();
			_head->_next = _head->_prev = _head;
		}
		List(size_t n, T data = T())
		{
			_head = NewNode();
			_head->_next = _head->_prev = _head;
			for (int i = 0; i < n; i++)
			{
				push_back(data);
			}
		}
		List(int n, T data = T())
		{
			_head = NewNode();
			_head->_next = _head->_prev = _head;
			for (int i = 0; i < n; i++)
			{
				push_back(data);
			}
		}
		template <class Iterator>
		List(Iterator start, Iterator end)
		{
			_head = NewNode();
			_head->_next = _head->_prev = _head;
			auto it = start;
			while (it != end)
			{
				push_back(*it);
				it++;
			}
		}
		List(const List<T>& l)
		{
			_head = NewNode();
			_head->_next = _head->_prev = _head;
			List<T> tmp(l.begin(), l.end());
			swap(tmp);
		}
		List<T>& operator=(List<T> l)
		{
			swap(l);
			return *this;
		}
		Node* NewNode(const T& x = T())
		{
			Node* newnode = new Node(x);
			return newnode;
		}
		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		// List Access
		T& front()
		{
			return begin().node->_data;
		}
		const T& front()const
		{
			return begin().node->_data;
		}
		T& back()
		{
			return (--end()).node->_data;
		}
		const T& back()const
		{
			return (--end()).node->_data;
		}

		//Modifiers:
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void insert(iterator pos, const T& x)
		{
			Node* next = pos.node;
			Node* prev = pos.node->_prev;
			Node* cur = NewNode(x);

			prev->_next = cur;
			cur->_next = next;
			next->_prev = cur;
			cur->_prev = prev;
		}
		void erase(iterator pos)
		{
			assert(pos != end());
			Node* next = pos.node->_next;
			Node* prev = pos.node->_prev;
			Node* cur = pos.node;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
		}
		void swap(List<T>& lt)
		{
			std::swap(_head, lt._head);
		}
		void clear()
		{
			size_t sz = size();
			while (sz--)
			{
				pop_back();
			}
		}
		//Capacity:
		bool empty()
		{
			return _head == _head->_next;
		}
		size_t size()
		{
			auto it = begin();
			size_t sz = 0;
			while (it != end())
			{
				it++;
				sz++;
			}
			return sz;
		}
		size_t capacity()
		{
			return size();
		}
	private:
		Node* _head;
	};

	template<class InputIterator, class T>
	InputIterator find(InputIterator first, InputIterator last, const T& val)
	{
		while (first != last) {
			if (*first == val) return first;
			++first;
		}
		return last;
	}
}