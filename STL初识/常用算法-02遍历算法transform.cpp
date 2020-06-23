#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>

void print01(int val)
{
	cout <<"\t"<< val << " ";
}
class Transform
{
public:
	int operator()(int v)
	{
		return v*v;
	}
};
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << "\t" << val << " ";
	}
};
void test01()
{
	//源容器
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), print01);
	cout << endl;
	//目标容器
	vector<int>v2;
	//目标容器需要提前开辟空间
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), Transform());
	//遍历
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}