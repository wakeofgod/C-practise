#include <iostream>
#include <string>
#include <set>
using namespace std;


class MyCompare 
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void printSet(const set<int> &s)
{
	for (set<int>::const_iterator i = s.begin(); i !=s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	printSet(s1);

	//指定排序规则从大到小
	set<int,MyCompare>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);
	for (set<int,MyCompare>::iterator i = s2.begin(); i !=s2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}