#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
//内建仿函数对象  关系仿函数
void printVector(vector<int> &v)
{
	for (vector<int>::iterator i = v.begin(); i !=v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
class Mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);
	printVector(v);
	//自定义的仿函数排序
	//sort(v.begin(), v.end(), Mycompare());
	//内建的仿函数对象
	sort(v.begin(), v.end(), greater<int>());
	printVector(v);
}
int main() {
	test01();
	system("pause");
	return 0;
}