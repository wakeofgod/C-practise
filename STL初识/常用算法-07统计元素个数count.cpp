#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//查找内置类型
void test01()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	int num = count(v.begin(), v.end(),1);
	cout << "找到的个数:" << num << endl;
}
//查找自定义类型
class Person
{
public :
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person &p)
	{
		return this->m_Age == p.m_Age;
	}
	string m_Name;
	int m_Age;
};
void test02()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 20);
	Person p5("eee", 10);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person p6("fff", 20);
	int num = count(v.begin(), v.end(), p6);
	cout << "找到年龄20的个数:" << num << endl;
}
int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}