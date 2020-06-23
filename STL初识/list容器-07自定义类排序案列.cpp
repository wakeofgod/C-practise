#include <iostream>
#include <string>
#include <list>
using namespace std;

//����list���Զ���������
//���������������������ͬ��������߽���
class Person 
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;		//����
	int m_Age;			//����
	int m_Height;		//	���
};
//ָ���������
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
		cout << "����:" << it->m_Name << "\t����:" << it->m_Age << "\t���:" << it->m_Height << endl;
	}
}
void test01()
{
	//����
	list<Person>L;
	//׼������
	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 175);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "����ǰ:" << endl;
	printPerson(L);
	cout << "======================="<<endl;
	cout << "�����:" << endl;
	L.sort(comparePerson);
	printPerson(L);
}
int main()
{
	test01();
	system("pause");
	return 0;
}