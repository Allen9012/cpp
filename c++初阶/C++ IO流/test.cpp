#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
class AT
{
public:
	void f1(const T& x)
	{
		cout << "void f1()" << endl;
	}

	void f2(const T& x)
	{
		cout << "void f2()" << endl;
	}

	void f3(const T& x)
	{
		cout << "void f3()" << endl
	}
};

//int main()
//{
//	AT<int> at1;
//	AT<double> at2;
//	AT<char> at3;
//
//	at1.f1(0);
//	at2.f1(1.1);
//	at2.f2(1.1);
//
//	return 0;
//}

struct Student
{
	string _name = "peter";
	int _age = 18;
	// ...
};

//int main()
//{
//	cout << "�������" << endl;
//	cerr << "�������" << endl;
//	clog << "��־���" << endl;
//
//	Student s;
//	//cin >> s._name >> s._age;
//	//cout << "���֣�" << s._name << " ���䣺" << s._age << endl;
//
//	//s._name.resize(100);
//	//scanf("%s%d", s._name.c_str(), &s._age); // ��������ô��
//	//printf("���֣�%s ���䣺%d\n", s._name.c_str(), s._age);
//	//cout << "���֣�" << s._name << " ���䣺" << s._age << endl;
//
//	// ���������ĳ������Կ�����c��
//	double d = 1.0 / 3.0;
//	printf("%.2f\n", d);
//	printf("���֣�%s ���䣺%d\n", s._name.c_str(), s._age);
//
//	// ���飺
//	// 1��C++����ȥ��cin��cout��������������
//	// 2����cout��cin������ĵط�����ȥ��scanf��printf
//
//
//	return 0;
//}

//int main()
//{
//	string line;
//	cin >> line;
//	cout << line << endl;
//
//	cin >> line;
//	cout << line << endl;
//
//	getline(cin, line);  // ��ȡ�ַ����Ի��з�����
//	cout << line << endl;
//}

//int main()
//{
//	// ��Щoj���в���������Ҫ�������������
//	// ctrl + c
//	string str;
//	// operator>>(cin, str) -> return cin����, 
//	// cin���ȥ��while���߼��ж���
//	while (cin >> str)  
//	{
//		// ...
//		cout << str << endl;
//	}
//
//	char buff[100];
//	while (scanf("%s", buff) != EOF)
//	{
//		printf("%s\n", buff);
//	}
//}

//void ReadFile()
//{
//	ifstream ifs("Test.cpp");
//	char ch;
//	/*while ((ch = ifs.get()) != EOF)
//	{
//		cout << ch;
//	}*/
//	/*while (ifs.get(ch))
//	{
//		cout << ch;
//	}*/
//	while (ifs)
//	{
//		cout << (char)ifs.get();
//	}
//}
//
//void WriteFile()
//{
//	ofstream ofs("write.txt");
//	ofs.put('x');
//	ofs.write("hello world", 10);
//}
//
//int main()
//{
//	ReadFile();
//	WriteFile();
//
//	return 0;
//}

struct ServerInfo
{
	char _ip[20];
	int  _port;
};

struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs.read((char*)&info, sizeof(info));
	}

	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs.write((char*)&info, sizeof(info));
	}

	void WriteTxt(const ServerInfo& info)
	{
		/*ofstream ofs(_filename);
		ofs.write(info._ip, strlen(info._ip));
		ofs.put('\n');
		string portstr = to_string(info._port);
		ofs.write(portstr.c_str(), portstr.size());*/

		// C++�����ṩ�ģ�������cһ��������ʵ��
		ofstream ofs(_filename);
		ofs << info._ip << "\n" << info._port;
	}

	void ReadTxt(ServerInfo& info)
	{
		//ifstream ifs(_filename);
		//ifs.getline(info._ip, 20);
		//// 
		//char portbuff[20];
		//ifs.getline(portbuff, 20);
		//info._port = stoi(portbuff);

		// C++�����ṩ�ģ�������cһ��������ʵ��
		ifstream ifs(_filename);
		ifs >> info._ip >> info._port;
	}

private:
	string _filename;
};

//int main()
//{
//	ServerInfo rinfo;
//	ServerInfo winfo = {"192.0.0.1", 8000};
//	// ��д -- ������  -- ��д�򵥡���Ч��ݡ� ȱ�㣺�����ַ����ַ������ڴ���д���ļ���������
//	/*ConfigManager cfbin("config.bin");
//	cfbin.WriteBin(winfo);*/
//	//ConfigManager cfbin("config.bin");
//	//cfbin.ReadBin(rinfo);
//
//	// ��д -- �ı�
//	//ConfigManager cftxt("config.txt");
//	//cftxt.WriteTxt(winfo);
//
//	ConfigManager cftxt("config.txt");
//	cftxt.ReadTxt(rinfo);
//
//
//	return 0;
//}

struct Message
{
	char _name[20];
	int  _id;
	char _time[20];
	char _str;
};

int main()
{
	ServerInfo info = { "192.0.0.1", 8000 };
	char buff[128];

	////c�����ṩ��
	//// ���л�
	//sprintf(buff, "%s %d", info._ip, info._port);

	//// �����л�
	//ServerInfo rinfo;
	//sscanf(buff, "%s%d", rinfo._ip, &rinfo._port);

	stringstream ssm;


	ssm << info._ip << " " << info._port;
	string buff = ssm.str();

	stringstream ssm;
	ssm.str("127.0.0.1 90");

	stringstream ssm("127.0.0.1 90");
	ServerInfo rinfo;
	ssm >> rinfo._ip >> rinfo._port;

	return 0;
}