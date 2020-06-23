#include <iostream>
#include <string>
#include <list>
using namespace std;

//利用list对自定义类排序
//按照年龄升序，如果年龄相同，按照身高降序
class Person 
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;		//姓名
	int m_Age;			//年龄
	int m_Height;		//	身高
};
//指定排序规则
bool comparePerson(Person &p1,Person &p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}
void printPerson(const list<Person> &L)
{
	for (list<Person>::const_iterator it = L.begin(); it!=L.end(); it++)
	{
		cout << "姓名:" << it->m_Name << "\t年龄:" << it->m_Age << "\t身高:" << it->m_Height << endl;
	}
}
void test01()
{
	//创建
	list<Person>L;
	//准备数据
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 175);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "排序前:" << endl;
	printPerson(L);
	cout << "======================="<<endl;
	cout << "排序后:" << endl;
	L.sort(comparePerson);
	printPerson(L);
}
int main()
{
	test01();
	system("pause");
	return 0;
}