#pragma once
namespace allen
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;

		vector(initializer_list<T> l)
		{
			_start = new T[l.size()];
			_finish = _start + l.size();
			_endofstorage = _start + l.size();

			iterator vit = _start;
			/*typename initializer_list<T>::iterator lit = l.begin();
			while (lit != l.end())
			{
				*vit++ = *lit++;
			}*/

			for (auto e : l)
				*vit++ = e;
		}

		vector<T>& operator=(initializer_list<T> l) {
			vector<T> tmp(l);
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);

			return *this;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
