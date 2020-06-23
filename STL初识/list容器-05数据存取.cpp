#include <iostream>
#include <string>
#include <list>
using namespace std;

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//L1[0]
	cout << "第一个元素是:" << L1.front() << endl;
	cout << "最后一个元素是:" << L1.back() << endl;
	//验证迭代器不支持随机访问
	list<int>::iterator it = L1.begin();
	//允许it++,禁止it+1
	it++;
	//it = it + 1;
}
int main() {
	test01();
	system("pause");
	return 0;
}