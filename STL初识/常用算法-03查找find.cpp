#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
	if (it != v1.end()) 
	{
		cout << "�ҵ�Ԫ��:" << *it << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator == (const Person &p)
	{
		if (this->m_Name == p.m_Name &&this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};
//�����Զ������ͣ���������==����find�ײ�֪����ô�Ա�
void test02()
{
	vector<Person> v1;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	Person pp("bbb", 20);
	vector<Person>::iterator it = find(v1.begin(), v1.end(), p2);
	if (it != v1.end())
	{
		cout << "�ҵ�Ԫ�� ����:" << it->m_Name << "\t ����:" << it->m_Age << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}
int main() {
	test01();
	//
	cout << "=======================" << endl;
	test02();
	system("pause");
	return 0;
}