#pragma once
class StackOnly
{
public:
	//static StackOnly CreateObj()
	//{
	//	return StackOnly();
	//}
	StackOnly() {};
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	//StackOnly() {}
	//void* operator new(size_t size);
	//void operator delete(void* p);
};