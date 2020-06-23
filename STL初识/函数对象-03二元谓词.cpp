#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

void printVector(vector<int> &v)
{
	for (vector<int>::iterator i = v.begin(); i !=v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
class MyCompare 
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test01()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(50);
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(30);
	sort(v1.begin(), v1.end());
	printVector(v1);
	//使用函数对象，改变排序规则
	sort(v1.begin(), v1.end(),MyCompare());
	cout << "======================" << endl;
	printVector(v1);
}
int main() {
	test01();
	system("pause");
	return 0;
}