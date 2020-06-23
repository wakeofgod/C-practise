#include <iostream>
#include <string>
#include <set>
using namespace std;

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
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	set<int>::iterator pos = s1.find(300);
	if (pos != s1.end())
	{
		cout << "找到元素:" << *pos << endl;
	}
	else
	{
		cout << "未找到元素:" << endl;
	}
}
//统计
void test02()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	int count = s1.count(30);
	cout << "num=" << count << endl;
	multiset<int>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(30);
	s2.insert(30);
	s2.insert(30);
	count = s2.count(30);
	cout << "num=" << count << endl;
}
int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}