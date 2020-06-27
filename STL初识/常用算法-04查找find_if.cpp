#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>

//1查找内置数据类型
class GeaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GeaterFive());
	if (it != v.end())
	{
		cout << "找到大于5的数字:" << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
//查找自定义类型
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(const Person &p)
	{
		return p.m_Age > 20;
	}
};
void test02()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it != v.end())
	{
		cout << "找到大于20的人 姓名:" << it->m_Name<<"年龄:"<<it->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
int main() {
	//test01();

	test02();
	system("pause");
	return 0;
}