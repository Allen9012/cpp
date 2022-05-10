#include "RB-tree.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "set.h"

using namespace std;
int main()
{
	allen::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(9, 9));

	allen::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	allen::set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(0);
	s.insert(15);
	s.insert(18);

	allen::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	allen::set<int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;

	//allen::list<int> lt;
	//lt.push_back(1);
	//lt.push_back(2);
	//lt.push_back(3);
	//lt.push_back(4);

	//allen::list<int>::reverse_iterator rit = lt.rbegin();
	//while (rit != lt.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	allen::map<string, string> dict;
	dict["sort"];
	dict["left"] = "左边";
	dict["left"] = "左边，剩余";

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	dict["sort"] = "排序";

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}

	return 0;
}