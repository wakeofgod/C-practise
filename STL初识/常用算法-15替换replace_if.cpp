#include <iostream>
#include <algorithm>
#include <string>
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
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	cout << "Ìæ»»Ç°" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	replace_if(v.begin(), v.end(), Greater20(),3000);
	cout << "Ìæ»»ºó" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}