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
		cout << "找到元素，key是:" << pos->first<<"\tvalue是:"<<pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
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