#include <iostream>
#include <string>
#include <map>
using namespace std;

void printMap(map<int,int> &m)
{
	for (map<int,int>::iterator i = m.begin(); i !=m.end(); i++)
	{
		cout << "key=" << i->first << "\t value=" << i->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	if (m1.empty())
	{
		cout << "mΪ��" << endl;
	}
	else
	{
		cout << "m��Ϊ��,��С��:"<<m1.size() << endl;
		printMap(m1);
	}
}
//����
void test02()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "����ǰ:" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "������:" << endl;
	printMap(m1);
	printMap(m2);
}
int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}