#pragma once
class HeapOnly
{
public:
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}

	//C++11 �ṩ
	HeapOnly(const HeapOnly&) = delete;

private:
	HeapOnly()
	{}
	//˽�л���ֻ������ʵ�֣�����ʵ�ֵ�û��Ҫ��
	//C++98 -- ��ֹ����
	//HeapOnly(const HeapOnly& );
};