#pragma once
#include<vector>
#include<list>
#include<deque>

namespace allen
{
	// 常规实现数据结构的思路
	//template<class T>
	//class stack
	//{
	//public:
	//	// ....
	//private:
	//	T* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};

	// 容器适配器
	//template<class T, class Container = std::vector<T>>
	//template<class T, class Container = std::list<T>>
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}