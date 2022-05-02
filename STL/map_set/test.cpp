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

	// 1、排序+去重
	// 遍历方式1：
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// 不能修改已经插入的值
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

	// 遍历方式2：
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 检查单词拼写是否正确
	// 思路：词库中单词都放进set的对象中，把每个写出来的单词
	// 去set中查一下，在不在，在就是正确的，不在就是错误的拼写
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
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	ret = strSet.find("map");
	if (ret != strSet.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
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

	// 先查找，找到了再删。没找到，也去删会报错
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

	// 在就删除，不在就不处理也不报错
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
	// multiset允许键值冗余，使用方法基本跟set一致
	// 就下面几个地方有一些差异
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

	// 排序
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// find查找的val有多个的时候，那么他找到的是中序的第一个
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
	// 调用pair的构造函数，构造一个匿名对象插入
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));
	m.insert(pair<int, double>(2, 3.3)); // key相同就会插入失败

	// 调用函数模板，构造对象，
	// 好处:是不需要去声明pair的参数，让函数模板自己推演，用起来方便些
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
	// 项目不展开命名空间，都要指定std，写起来会比较长
	//std::map<std::string, std::string> dict;
	//dict.insert(std::pair<std::string, std::string>("insert", "插入"));
	//dict.insert(std::make_pair("sort", "排序"));
	//dict.insert(std::make_pair("left", "左边"));

	////std::map<std::string, std::string>::iterator it = dict.begin();
	//auto dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	cout << dit->first << ":" << dit->second << endl;
	//	++dit;
	//}
	//cout << endl;

	// 通过typedef 简化命名
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(std::make_pair("sort", "排序"));
	dict.insert(std::make_pair("left", "左边"));

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
	// 通过typedef 简化命名
	typedef std::map<std::string, std::string> POKEMON;
	typedef std::pair<std::string, std::string> POKEMON_KV;
	typedef std::map<std::string, std::string>::iterator POKEMON_ITER;

	POKEMON pokemon;
	pokemon.insert(pair<string,string>("卡比兽", "一般"));
	pokemon.insert(POKEMON_KV("喷火龙","火"));
	pokemon.insert(make_pair("皮卡丘", "电"));

	// 修改map的value数据
	auto ret = pokemon.find("喷火龙");
	if (ret != pokemon.end())
	{
		//ret->second.insert(ret->second.size(), "、飞行");
		// 可读性优化技巧
		string& str = ret->second;
		str += "、飞行";
	}

	//修改value显示的时候加一个括号
	POKEMON_ITER pok = pokemon.begin();
	while (pok != pokemon.end())
	{
		pok->second.insert(0, "【");
		pok->second += "】";
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
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(DICT_KV("sort", "排序"));
	dict.insert(DICT_KV("left", "左边"));

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

	// 修改map的value数据
	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//ret->second.insert(ret->second.size() - 1, "、剩余");
		// 可读性优化技巧
		string& str = ret->second;
		str.insert(str.size() - 1, "、剩余");
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
	// 1、统计次数 
	string arr[] = { "皮卡丘", "喷火龙", "皮卡丘", "妙蛙种子", "水跃鱼", 
		"皮卡丘", "喷火龙", "喷火龙","喷火龙","喷火龙", "皮卡丘", "水跃鱼", "喷火龙" };

	//// 统计次数的方式1：
	//map<string, int> countMap;
	//for (const auto& str : arr)
	//{
	//	// 思路：第一次出现，插入<str, 1>, 后续再出现就++次数ret->second
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
	
	// //统计次数的方式2： 
	//map<string, int> countMap;
	//for (const auto& str : arr)
	//{
	//	// 先插入，如果str已经在map中，insert会返回str所在节点的迭代器，我们++次数即可
	//	//pair<map<string, int>::iterator, bool>  ret = countMap.insert(make_pair(str, 1));
	//	auto ret = countMap.insert(make_pair(str, 1));//返回值ret是pair类型的
	//	if (ret.second == false)
	//	{//first是迭代器，迭代器指向的value++
	//		ret.first->second++;
	//	}
	//}

	// 统计次数方式3：
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}

	// 关于[]的一些扩展学习
	map<string, string> pokemon;
	pokemon.insert(make_pair("皮卡丘", "一般"));
	pokemon["皮卡丘"] = "电";  // 插入+修改
	pokemon["卡比兽"]; // 插入
	pokemon["卡比兽"] = "一般";     // 修改
	pokemon["喷火龙"] = "火、飞行";  // 修改
	pokemon.erase("喷火龙");
}

struct MapItCompare
{//降序
	bool operator()( map<string, int>::iterator x,  map<string, int>::iterator y) const
	{
		return x->second < y->second;
	}
};

void test_map4()
{
	string arr[] = { "香蕉", "苹果", "香蕉", "榴莲", "草莓", "苹果", "香蕉", "苹果", "西瓜", "西瓜", "香蕉", "草莓", "西瓜" };
	map<string, int> countMap;
	//1. 统计次数
	for (const auto& str : arr)
	{
		countMap[str]++;
	}

	// 2. 对所有水果次数排序的思路
	////vector<pair<string, int>> v;//不要放数据进vector
	//vector<map<string, int>::iterator> v;//放指针
	map<string, int>::iterator countMapIt = countMap.begin();
	//while (countMapIt != countMap.end())
	//{
	//	v.push_back(countMapIt);
	//	++countMapIt;
	//}
	////排序
	//sort(v.begin(), v.end(), MapItCompare());

	// 利用map排序  -- 拷贝pair数据
	//map<int, string> sortMap;
	//map<int, string, greater<int>> sortMap;
	//for (auto e : countMap)
	//{
	//	sortMap.insert(make_pair(e.second, e.first));
	//}

	// 利用set排序  --不拷贝pair数据
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
	pokemon.insert(make_pair("喷火龙", "火"));
	pokemon.insert(make_pair("喷火龙", "飞行"));

	multimap<string, string> mpokemon;
	mpokemon.insert(make_pair("喷火龙", "火"));
	mpokemon.insert(make_pair("喷火龙", "飞行"));
	mpokemon.insert(make_pair("喷火龙", "火"));
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