#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test01()
{
	vector<int> v;
	int num=0;
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//如果指针不指向第一个元素，代表容器在动态扩展
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}		
	}
	cout << "vector容器动态扩展的次数是:" << num << endl;
}
void test02()
{
	vector<int> v;
	//指定预留空间大小
	v.reserve(100000);
	int num = 0;
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//如果指针不指向第一个元素，代表容器在动态扩展
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "预留空间后vector容器动态扩展的次数是:" << num << endl;
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}