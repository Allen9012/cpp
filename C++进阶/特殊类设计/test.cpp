#include<iostream>
#include <mutex>
using namespace std;

#include"HeapOnly.h"
#include "StackOnly.h"
#include "CopyLimit.h"
#include "NonInherit.h"

// 单例模式

// 单例类并不是一定要用这个名字
// 如果保证全局(一个进程中)只有一个唯一实例对象
// 1、构造函数私有定义。拷贝构造和赋值防拷贝禁掉
// 2、提供一个GetInstance获取单例对象

// 饿汉模式 -- 程序开始main执行之前就创建单例对象
// 提供一个静态指向单例对象的成员指针，初始化时new一个对象给它
namespace hungry
{
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return _inst;
		}
		void Print()
		{
			cout << _str << endl;
		}

	private:
		Singleton()
			:_str("")
		{}

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		string _str = "言之命至";
		static Singleton* _inst;
	};
	Singleton* Singleton::_inst = new Singleton;
}

namespace lazy
{
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			if (_inst==nullptr)
			{
				_mutex.lock();
				if (_inst == nullptr)
				{
					_inst = new Singleton;
				}
				_mutex.unlock();
			}

			return _inst;
		}

		static void DelInstance()
		{
			_mutex.lock();
			if (_inst)
			{
				delete _inst;
				_inst = nullptr;
			}
			_mutex.unlock();
		}

		class CGarbo 
		{
			~CGarbo()
			{
				if (_inst)
				{
					delete _inst;
					_inst = nullptr;
				}
			}
		};

	

	private:
		Singleton()
		{
			//假设到哪里类构造函数中，要做很多配置初始化
		}
		~Singleton()
		{
			//程序结束的时候，需要处理一下
		}

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		static Singleton* _inst;
		static std::mutex _mutex;
		static CGarbo _gc;
	};
	Singleton* Singleton::_inst = nullptr;
	std::mutex Singleton::_mutex;
	Singleton::CGarbo Singleton::_gc;

}

// 懒汉模式和饿汉模式的对比
// 饿汉
// 优点：简单 
// 缺点：1、如果单例对象构造函数工作比较多，会导致程序启动慢,迟迟进不了入口main函数
//       2、如果有多个单例对象，他们之间有初始化依赖关系，饿汉模式也会有问题。 
//       比如有A和B两个单例类，要求A单例先初始化，B必须在A之后初始化。那么饿汉无法保证
//       这种场景下面用懒汉就可以，懒汉可以先调用A::GetInstance(),再调用B::GetInstance().
// 懒汉
// 优点：解决上面饿汉的缺点。因为他是第一次调用GetInstance时创建初始化单例对象
// 缺点：相对饿汉，复杂一点点。

// 迭代器模式、适配器模式
// 设计模式有兴趣的同学，可以下去再看看工厂模式、观察者模式等等

//其他版本懒汉

namespace lazy2
{
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			static Singleton inst;
			return &inst;
		}


	private:
		Singleton()
		{
			//假设到哪里类构造函数中，要做很多配置初始化
		}

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		static std::mutex _mutex;
	};
	std::mutex Singleton::_mutex;
}


int main()
{
	//HeapOnly ho;
	//HeapOnly* p = new HeapOnly;
	
	//HeapOnly* p = HeapOnly::CreateObj();
	//HeapOnly copy(*p);

	//StackOnly so;
	//StackOnly* ps = new StackOnly;

	cout << lazy::Singleton::GetInstance() << endl;

	lazy::Singleton::GetInstance();
	return 0;
}