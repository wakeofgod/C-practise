#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//binary_search 查找指定元素，不能在无序序列中使用
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//在有序之后插入值打乱，结果会很不稳定
	v.push_back(2);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret)
	{
		cout << "找到" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
int main() {
	test01();
	system("pause");
	return 0;
}