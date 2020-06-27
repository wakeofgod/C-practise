#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>

//1����������������
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
		cout << "�ҵ�����5������:" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
//�����Զ�������
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
		cout << "�ҵ�����20���� ����:" << it->m_Name<<"����:"<<it->m_Age << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
int main() {
	//test01();

	test02();
	system("pause");
	return 0;
}