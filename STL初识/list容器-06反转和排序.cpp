#include <iostream>
#include <string>
#include <list>
#include<algorithm>
using namespace std;

void printList(const list<int> &L)
{
	for (list<int>::const_iterator it = L.begin(); it !=L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);

	cout << "反转前" << endl;
	printList(L1);
	cout << "反转后" << endl;
	L1.reverse();
	printList(L1);
}
bool myCompare(int v1,int v2) 
{
	//降序，让第一个数大于第二个数
	return v1 > v2;
}
void test02()
{
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(50);
	L1.push_back(40);
	L1.push_back(30);

	cout << "排序前" << endl;
	printList(L1);
	cout << "排序后" << endl;
	//所有不支持随机访问迭代器的容器，不可以使用标准算法排序，内部会提供一些对应算法
	L1.sort();//默认排序规则，从小到大，升序 
	printList(L1);
	//调用自定义排序规则的回调函数
	L1.sort(myCompare);
	printList(L1);
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}