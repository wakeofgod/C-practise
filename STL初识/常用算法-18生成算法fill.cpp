#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
#include <algorithm>

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
	vector<int>v;
	v.resize(10,10);
	//初始
	cout << "初始值" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	cout << "更改fill后" << endl;
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}