#pragma once
class HeapOnly
{
public:
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

	//C++11 提供
	HeapOnly(const HeapOnly&) = delete;

private:
	HeapOnly()
	{}
	//私有化，只声明不实现（可以实现但没必要）
	//C++98 -- 防止拷贝
	//HeapOnly(const HeapOnly& );
};