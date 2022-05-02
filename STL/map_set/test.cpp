#include<iostream>
#include<set>
#include<map>
#include<string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);

	// 1������+ȥ��
	// ������ʽ1��
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// �����޸��Ѿ������ֵ
		// *it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// ������ʽ2��
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ��鵥��ƴд�Ƿ���ȷ
	// ˼·���ʿ��е��ʶ��Ž�set�Ķ����У���ÿ��д�����ĵ���
	// ȥset�в�һ�£��ڲ��ڣ��ھ�����ȷ�ģ����ھ��Ǵ����ƴд
	set<string> strSet;
	strSet.insert("sort");
	strSet.insert("left");
	strSet.insert("right");
	strSet.insert("insert");

	for (const auto& e : strSet)
	{
		cout << e << " ";
	}
	cout << endl;

	// ...
	set<string>::iterator ret = strSet.find("sort");
	if (ret != strSet.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	ret = strSet.find("map");
	if (ret != strSet.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

void test_set2()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);

	// �Ȳ��ң��ҵ�����ɾ��û�ҵ���Ҳȥɾ�ᱨ��
	auto pos = s.find(4);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	pos = s.find(40);
	//s.erase(pos);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	// �ھ�ɾ�������ھͲ�����Ҳ������
	s.erase(3);
	s.erase(30);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	// multiset�����ֵ���࣬ʹ�÷���������setһ��
	// �����漸���ط���һЩ����
	multiset<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(3);

	// ����
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// find���ҵ�val�ж����ʱ����ô���ҵ���������ĵ�һ��
	multiset<int>::iterator pos = s.find(3);
	while (*pos == 3)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << s.count(3) << endl;
	cout << s.count(4) << endl;

	s.erase(3);
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//};

//template <class T1, class T2>
//pair<T1, T2> make_pair(T1 x, T2 y)
//{
//	return (pair<T1, T2>(x, y));
//}

void test_map1()
{
	map<int, double> m;
	// ����pair�Ĺ��캯��������һ�������������
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));
	m.insert(pair<int, double>(2, 3.3)); // key��ͬ�ͻ����ʧ��

	// ���ú���ģ�壬�������
	// �ô�:�ǲ���Ҫȥ����pair�Ĳ������ú���ģ���Լ����ݣ�����������Щ
	m.insert(make_pair(2, 2.2));

	map<int, double>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << (*it).first <<":"<<(*it).second<<endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	//map<string, string> dict;
	// ��Ŀ��չ�������ռ䣬��Ҫָ��std��д������Ƚϳ�
	//std::map<std::string, std::string> dict;
	//dict.insert(std::pair<std::string, std::string>("insert", "����"));
	//dict.insert(std::make_pair("sort", "����"));
	//dict.insert(std::make_pair("left", "���"));

	////std::map<std::string, std::string>::iterator it = dict.begin();
	//auto dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	cout << dit->first << ":" << dit->second << endl;
	//	++dit;
	//}
	//cout << endl;

	// ͨ��typedef ������
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(std::make_pair("sort", "����"));
	dict.insert(std::make_pair("left", "���"));

	DICT_ITER dit = dict.begin();
	//auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}

void test1()
{
	// ͨ��typedef ������
	typedef std::map<std::string, std::string> POKEMON;
	typedef std::pair<std::string, std::string> POKEMON_KV;
	typedef std::map<std::string, std::string>::iterator POKEMON_ITER;

	POKEMON pokemon;
	pokemon.insert(pair<string,string>("������", "һ��"));
	pokemon.insert(POKEMON_KV("�����","��"));
	pokemon.insert(make_pair("Ƥ����", "��"));

	// �޸�map��value����
	auto ret = pokemon.find("�����");
	if (ret != pokemon.end())
	{
		//ret->second.insert(ret->second.size(), "������");
		// �ɶ����Ż�����
		string& str = ret->second;
		str += "������";
	}

	//�޸�value��ʾ��ʱ���һ������
	POKEMON_ITER pok = pokemon.begin();
	while (pok != pokemon.end())
	{
		pok->second.insert(0, "��");
		pok->second += "��";
		cout << pok->first << ":" << pok->second << endl;
		++pok;
	}
	cout << endl;
}

void test_map2()
{
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(DICT_KV("sort", "����"));
	dict.insert(DICT_KV("left", "���"));

	DICT_ITER dit = dict.begin();
	while (dit != dict.end())
	{
		dit->second.insert(0, "{");
		dit->second += "}";

		++dit;
	}
	cout << endl;

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;

	// �޸�map��value����
	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//ret->second.insert(ret->second.size() - 1, "��ʣ��");
		// �ɶ����Ż�����
		string& str = ret->second;
		str.insert(str.size() - 1, "��ʣ��");
	}

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}

void test_map3()
{
	// 1��ͳ�ƴ��� 
	string arr[] = { "Ƥ����", "�����", "Ƥ����", "��������", "ˮԾ��", 
		"Ƥ����", "�����", "�����","�����","�����", "Ƥ����", "ˮԾ��", "�����" };

	//// ͳ�ƴ����ķ�ʽ1��
	//map<string, int> countMap;
	//for (const auto& str : arr)
	//{
	//	// ˼·����һ�γ��֣�����<str, 1>, �����ٳ��־�++����ret->second
	//	map<string, int>::iterator ret = countMap.find(str);
	//	if (ret != countMap.end())
	//	{
	//		ret->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}
	//for (const auto& e : countMap)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}
	
	// //ͳ�ƴ����ķ�ʽ2�� 
	//map<string, int> countMap;
	//for (const auto& str : arr)
	//{
	//	// �Ȳ��룬���str�Ѿ���map�У�insert�᷵��str���ڽڵ�ĵ�����������++��������
	//	//pair<map<string, int>::iterator, bool>  ret = countMap.insert(make_pair(str, 1));
	//	auto ret = countMap.insert(make_pair(str, 1));//����ֵret��pair���͵�
	//	if (ret.second == false)
	//	{//first�ǵ�������������ָ���value++
	//		ret.first->second++;
	//	}
	//}

	// ͳ�ƴ�����ʽ3��
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	// ����[]��һЩ��չѧϰ
	map<string, string> pokemon;
	pokemon.insert(make_pair("Ƥ����", "һ��"));
	pokemon["Ƥ����"] = "��";  // ����+�޸�
	pokemon["������"]; // ����
	pokemon["������"] = "һ��";     // �޸�
	pokemon["�����"] = "�𡢷���";  // �޸�
	pokemon.erase("�����");
}

struct MapItCompare
{//����
	bool operator()( map<string, int>::iterator x,  map<string, int>::iterator y) const
	{
		return x->second < y->second;
	}
};

void test_map4()
{
	string arr[] = { "�㽶", "ƻ��", "�㽶", "����", "��ݮ", "ƻ��", "�㽶", "ƻ��", "����", "����", "�㽶", "��ݮ", "����" };
	map<string, int> countMap;
	//1. ͳ�ƴ���
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	// 2. ������ˮ�����������˼·
	////vector<pair<string, int>> v;//��Ҫ�����ݽ�vector
	//vector<map<string, int>::iterator> v;//��ָ��
	map<string, int>::iterator countMapIt = countMap.begin();
	//while (countMapIt != countMap.end())
	//{
	//	v.push_back(countMapIt);
	//	++countMapIt;
	//}
	////����
	//sort(v.begin(), v.end(), MapItCompare());

	// ����map����  -- ����pair����
	//map<int, string> sortMap;
	//map<int, string, greater<int>> sortMap;
	//for (auto e : countMap)
	//{
	//	sortMap.insert(make_pair(e.second, e.first));
	//}

	// ����set����  --������pair����
	set<map<string, int>::iterator, MapItCompare> sortSet;
	countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		sortSet.insert(countMapIt);
		++countMapIt;
	}

	typedef map<string, int>::iterator M_IT;
	priority_queue<M_IT, vector<M_IT>, MapItCompare> pq;
	countMapIt = countMap.begin();
	while (countMapIt != countMap.end())
	{
		pq.push(countMapIt);
		++countMapIt;
	}
}

void test_map5()
{
	map<string, string> pokemon;
	pokemon.insert(make_pair("�����", "��"));
	pokemon.insert(make_pair("�����", "����"));

	multimap<string, string> mpokemon;
	mpokemon.insert(make_pair("�����", "��"));
	mpokemon.insert(make_pair("�����", "����"));
	mpokemon.insert(make_pair("�����", "��"));
}

int main()
{
	//test_set3();
	//test_map5();

	/*cout << int() << endl;
	cout << int(10) << endl;
	cout << int(20) << endl;*/
	test_map5();


	return 0;
}