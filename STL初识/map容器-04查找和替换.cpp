#include <iostream>
#include <string>
#include <map>
using namespace std;

void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	map<int, int>::iterator pos = m1.find(3);
	if (pos != m1.end())
	{
		cout << "�ҵ�Ԫ�أ�key��:" << pos->first<<"\tvalue��:"<<pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	int num = m1.count(3);
	cout << "num=" << num << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}