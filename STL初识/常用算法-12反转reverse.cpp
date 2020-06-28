#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	cout << "反转前" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	reverse(v.begin(), v.end());
	cout << "反转后" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}