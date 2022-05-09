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


	allen::set<int,int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(0);
	s.insert(15);
	s.insert(18);


	allen::set<int,int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	allen::map<int, int>::iterator mit = m.begin();
	while (mit != m.end())
	{
		cout <<(* mit).first<<":"<< (*mit).second << " ";
		++mit;
	}
	cout << endl;
	return 0;
}