#include <iostream>
#include <string>
#include <map>
using namespace std;

class MyCompare 
{
public:
	bool operator ()(int v1, int v2) 
	{
		return v1 > v2;
	}
};
class Person
{
public :
	Person(string name,int age,int height) 
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
class PersonCompare
{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		if (p1.m_Age == p2.m_Age)
		{
			return p1.m_Height < p2.m_Height;
		}
		return p1.m_Age > p2.m_Age;
	}
};
void printMap(map<int, int,MyCompare> &m)
{
	for (map<int,int,MyCompare>::iterator i = m.begin(); i !=m.end(); i++)
	{
		cout << "key是:" << i->first << "\t value是:" << i->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int,MyCompare>m1;
	m1.insert(make_pair<int, int>(1, 10));
	m1.insert(make_pair<int, int>(2, 20));
	m1.insert(make_pair<int, int>(3, 30));
	m1.insert(make_pair<int, int>(4, 40));
	m1.insert(make_pair<int, int>(5, 50));
	
	printMap(m1);
}

void test02()
{
	map<Person, int,PersonCompare>m1;
	m1.insert(pair<Person, int>({ "刘备",30,175 }, 10));
	m1.insert(pair<Person, int>({ "关羽",25,195 }, 20));
	m1.insert(pair<Person, int>({ "张飞",25,185 }, 30));
	m1.insert(pair<Person, int>({ "赵云",21,190 }, 40));

	for (map<Person,int,PersonCompare>::iterator i = m1.begin(); i!=m1.end(); i++)
	{
		cout << "key是:" << i->first.m_Name << "\t value是:" << i->second << endl;
	}
}
int main() {
	test01();
	cout << "=======" << endl;
	test02();
	system("pause");
	return 0;
}