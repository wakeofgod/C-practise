#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v1;
	vector<int>v2;
	//原容器必须是有序序列
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	//目标容器需要开辟最大空间
	//最特殊情况，大容器包含小容器，开辟空间，取值小容器的size即可
	vTarget.resize(min(v1.size(), v2.size()));
	//获取交集
	vector<int>::iterator itEnd= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	cout << "显示交集部分" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint());
	cout << endl;
	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}