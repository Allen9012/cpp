#pragma once
namespace allen
{
	template<class T>
	struct less
	{
		bool operator()(const T& l, const T& r)
		{
			return l < r;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& l, const T& r)
		{
			return l > r;
		}
	};

	template <class T, class Container=vector<T>, class Compare=less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(size_t child)
		{
			Compare com;

			size_t parent = (child - 1) / 2;
			//child==0就是终止
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{//直接结束
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void AdjustDown(size_t parent)
		{
				Compare com;
				size_t child = parent * 2 + 1;
				while (child < _con.size())
				{//选出左右孩子中小的那一个，且判断右孩子存在
					if (child + 1 < _con.size() &&  com(_con[child] , _con[child + 1] ) )
					{
						++child;
					}

					if (com(_con[parent], _con[child]))
					{
						swap(_con[parent], _con[child]);
						parent = child;
						child = parent * 2 + 1;
					}
					else
					{
						break;
					}
				}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T top()
		{
			return _con[0];
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
		Container _con;//自定义类型，所以不需要写构造和析构函数
	};
}