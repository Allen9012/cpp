#pragma once
// ·´Ïòµü´úÆ÷--µü´úÆ÷ÊÊÅäÆ÷
template<class Iterator>
struct Reverse_Iterator
{
	typedef typename Iterator::reference Ref;
	typedef typename Iterator::pointer Ptr;
	typedef Reverse_Iterator<Iterator> Self;
	Iterator _it;

	Reverse_Iterator(Iterator it)
		:_it(it)
	{}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return _it.operator->();
	}

	Self& operator++()
	{
		--_it;
		return *this;
	}

	Self& operator--()
	{
		++_it;
		return* this;
	}

	bool operator!=(const Self& s) const
	{
		return _it != s._it;
	}

	bool operator==(const Self& s) const
	{
		return _it == s._it;
	}
};