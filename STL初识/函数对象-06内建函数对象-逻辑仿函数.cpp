#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
void printVector(vector<bool>&v)
{
	for (vector<bool>::iterator i = v.begin(); i !=v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test01()
{
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	printVector(v1);

	vector<bool>v2;
	//必须指定v2的大小，不然为空不能搬运v1
	v2.resize(v1.size());
	//调用逻辑非
	transform(v1.begin(), v1.end(),v2.begin(), logical_not<bool>());
	printVector(v2);
}
int main() {
	test01();
	system("pause");
	return 0;
}