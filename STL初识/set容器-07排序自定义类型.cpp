#include <iostream>
#include <string>
#include <set>
using namespace std;

class Person
{
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2) 
	{
		return p1.m_Age > p2.m_Age;
	}
};
void printPersonSet(const set<Person,comparePerson> &s)
{
	for (set<Person,comparePerson>::const_iterator i = s.begin(); i !=s.end(); i++)
	{
		cout << "姓名:" << i->m_Name << "\t年龄:" << i->m_Age << endl;
	}
}
void test01()
{
	//自定义数据类型，不指定排序规则，插入会失败
	set<Person,comparePerson>s1;
	Person p1("刘备", 24);
	Person p2("关羽", 28);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	printPersonSet(s1);
}
int main() {
	test01();
	system("pause");
	return 0;
}