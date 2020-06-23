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
		cout << "����:" << i->m_Name << "\t����:" << i->m_Age << endl;
	}
}
void test01()
{
	//�Զ����������ͣ���ָ��������򣬲����ʧ��
	set<Person,comparePerson>s1;
	Person p1("����", 24);
	Person p2("����", 28);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);
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