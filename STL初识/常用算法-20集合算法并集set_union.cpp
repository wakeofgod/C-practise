#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class MyPrint
{
public:
	void operator ()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	//原容器必须是有序的
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
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