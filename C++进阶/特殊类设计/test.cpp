#include<iostream>
#include <mutex>
using namespace std;

#include"HeapOnly.h"
#include "StackOnly.h"
#include "CopyLimit.h"
#include "NonInherit.h"

// ����ģʽ

// �����ಢ����һ��Ҫ���������
// �����֤ȫ��(һ��������)ֻ��һ��Ψһʵ������
// 1�����캯��˽�ж��塣��������͸�ֵ����������
// 2���ṩһ��GetInstance��ȡ��������

// ����ģʽ -- ����ʼmainִ��֮ǰ�ʹ�����������
// �ṩһ����ָ̬��������ĳ�Աָ�룬��ʼ��ʱnewһ���������
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
		string _str = "��֮����";
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
			//���赽�����๹�캯���У�Ҫ���ܶ����ó�ʼ��
		}
		~Singleton()
		{
			//���������ʱ����Ҫ����һ��
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

// ����ģʽ�Ͷ���ģʽ�ĶԱ�
// ����
// �ŵ㣺�� 
// ȱ�㣺1��������������캯�������Ƚ϶࣬�ᵼ�³���������,�ٳٽ��������main����
//       2������ж��������������֮���г�ʼ��������ϵ������ģʽҲ�������⡣ 
//       ������A��B���������࣬Ҫ��A�����ȳ�ʼ����B������A֮���ʼ������ô�����޷���֤
//       ���ֳ��������������Ϳ��ԣ����������ȵ���A::GetInstance(),�ٵ���B::GetInstance().
// ����
// �ŵ㣺������������ȱ�㡣��Ϊ���ǵ�һ�ε���GetInstanceʱ������ʼ����������
// ȱ�㣺��Զ���������һ��㡣

// ������ģʽ��������ģʽ
// ���ģʽ����Ȥ��ͬѧ��������ȥ�ٿ�������ģʽ���۲���ģʽ�ȵ�

//�����汾����

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
			//���赽�����๹�캯���У�Ҫ���ܶ����ó�ʼ��
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