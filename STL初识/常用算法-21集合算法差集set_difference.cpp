#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
#include <vector>

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
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	//创建目标容器
	vector<int>vTarget;
	//最特殊的情况，两个容器没有交集，取最大的size
	vTarget.resize(max(v1.size(), v2.size()));
	
	vector<int>::iterator itEnd= set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	cout << "v1差集v2:" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint());
	cout << endl;
	cout << "===================" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	cout << "v2差集v1:" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}