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
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	cout << "Ìæ»»Ç°" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	replace(v1.begin(), v1.end(), 20, 2000);
	cout << "Ìæ»»ºó" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}