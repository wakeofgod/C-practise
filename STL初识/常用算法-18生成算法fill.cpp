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
	//��ʼ
	cout << "��ʼֵ" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	cout << "����fill��" << endl;
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}