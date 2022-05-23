#include<iostream>
#include<thread>
#include <vector>
#include <mutex>
using namespace std;



//int main()
//{
//	int n = 100;
//	//ż��
//	thread t1([n]
//		{
//			for (size_t i=0;i<n;i+=2)
//			{
//				cout << i << endl;
//			}
//		});
//	//����
//	thread t2([n]
//		{
//			for (size_t i = 1; i < n; i += 2)
//			{
//				cout << i << endl;
//			}
//		});
//	t1.join();
//	t2.join();
//	
//	return 0;
//}
//void f(int N)
//{
//	mtx.lock();
//	for (int i=0;i<N;++i)
//	{
//		cout <<this_thread::get_id()<<":"<< i << endl;
//	}
//	mtx.unlock();
//}


//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	mutex mtx;
//	int N = 1000000;
//	atomic<int> x = 0;
//	//atomic_int x = {0};
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &N, &x]
//		{
//			//mtx.lock();
//			for (int i = 0; i < N; ++i)
//			{
//				++x;
//			}
//			//mtx.unlock();
//		});
//	}
//
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//
//	printf("%d���̲߳��ж�x++��%d��,x:%d\n", n, N, x);
//
//	return 0;
//}


//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<thread> vthreads;
//	vthreads.resize(n);
//	mutex mtx;
//	int N = 100;
//	int x = 0;
//	for (auto& td : vthreads)
//	{
//		td = thread([&mtx, &N, &x]
//		{
//			for (int i = 0; i < N; ++i) 
//			{
//				mtx.lock(); 
//				cout << this_thread::get_id() << ":" << x << endl;
//				++x;
//				this_thread::sleep_for(chrono::milliseconds(500));
//				mtx.unlock(); 
//			}
//		});
//	}
//
//	for (auto& td : vthreads)
//	{
//		td.join();
//	}
//	return 0;
//}

//// RAII
//namespace allen
//{
//	template<class Lock>
//	class lock_guard
//	{
//	public:
//		lock_guard(Lock& lock)
//			:_lock(lock)
//		{
//			_lock.lock();
//			cout << "����" << endl;
//		}
//
//		/*void lock()
//		{
//		_lock.lock();
//		}
//
//		void unlock()
//		{
//		_lock.unlock();
//		}*/
//
//		~lock_guard()
//		{
//			_lock.unlock();
//			cout << "����" << endl;
//		}
//
//		lock_guard(const lock_guard<Lock>& lock) = delete;
//
//	private:
//		Lock& _lock;
//	};
//}
//
////mutex mtx;
////void func()
////{
////	// ����������ִ�У�������;���أ��������쳣��
////	// ��α�֤������һ��������?
////	//mtx.lock(); 
////	bit::lock_guard<mutex> lg(mtx);
////	// ...
////
////	FILE* fout = fopen("test.txt", "r");
////	if (fout == nullptr)
////	{
////		// ....
////		//mtx.unlock();
////		return;
////	}
////
////	int n;
////	cin >> n;
////	char* p = new char[n];  // ���쳣
////
////	// f1();				// ���쳣
////
////
////	// ...
////	//mtx.unlock();
////}
//
//mutex mtx;
//void func()
//{
//	// ����������ִ�У�������;���أ��������쳣��
//	// ��α�֤������һ��������?
//	//mtx.lock(); 
//	// ָ�����㱣�����ļ���δ��룿��ô��
//	{
//		allen::lock_guard<mutex> lg(mtx);
//
//		FILE* fout = fopen("test.txt", "r");
//		if (fout == nullptr)
//		{
//			// ....
//			//mtx.unlock();
//			//return;
//		}
//	}
//
//	int n;
//	cin >> n;
//	char* p = new char[n];  // ���쳣
//
//	// f1();				// ���쳣
//
//
//	// ...
//	//mtx.unlock();
//}
//
//int main()
//{
//	try {
//		func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
using namespace std;

int main()
{
	int n = 100;
	mutex mtx;

	// ���� ���� thread2�ٳ�û�����û���û���ŵ�cpuʱ��Ƭ���ͻᵼ��t1������ӡ����������������Ҫ��
	thread t1([&](){
		int i = 1;
		for (; i < n; i += 2)
		{
			unique_lock<mutex> lock(mtx);
			cout << i << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	});

	// ż��
	thread t2([&](){
		int j = 2;
		for (; j < n; j += 2)
		{
			unique_lock<mutex> lock(mtx);
			cout << j << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	});

	t1.join();
	t2.join();

	return 0;
}


//int main()
//{
//	int n = 100;
//	mutex mtx;
//	condition_variable cv;
//	bool flag = true;
//		// ����
//	thread t1([&](){
//		int i = 1;
//		while(i<=n)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&flag]()->bool{return flag; }); //��Ҫ����false����ִ��
//			cout << i << endl;
//			i += 2;
//			flag = false;
//			cv.notify_one();
//		}
//	});
//	// ż��
//	thread t2([&](){
//		int j = 2;
//		while(j<=n)
//		{
//			unique_lock<mutex> lock(mtx);
//			cv.wait(lock, [&flag]()->bool{return !flag; });  // ��Ҫ����false����ִ��
//			cout << j << endl;
//			j += 2;
//			flag = true; 
//			cv.notify_one();
//		}
//	});
//	t1.join();
//	t2.join();
//
//	return 0;
//}