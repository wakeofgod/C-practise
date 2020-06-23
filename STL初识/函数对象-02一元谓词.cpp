#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
//仿函数 返回值类型是bool类型，成为谓词
//一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器,有没有大于5 的数字
	//使用匿名对象GreaterFive()
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it != v.end())
	{
		//cout << "找到了" << *it << endl;
		for (; it != v.end(); it++)
		{
			cout << "找到了" << *it << endl;
		}
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