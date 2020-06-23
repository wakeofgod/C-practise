#include <iostream>
#include <vector>
#include <string>
using namespace std;

//vector容器互换
//基本使用

void printVector(vector<int> & v) 
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector <int>v2;
	for (int i = 10 ;i >0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	//
	cout << "交换后:" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
//实际用途
//巧用swap可以收缩空间
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v的容量是:" << v.capacity() << endl;
	cout << "v的大小是:" << v.size() << endl;
	v.resize(3);//重新指定大小
	cout << "重新制定后v的容量是:" << v.capacity() << endl;
	cout << "重新制定后v的大小是:" << v.size() << endl;
	//巧用swap收缩内存
    //创建一个匿名对象，拷贝v，然后和v交换
	vector<int>(v).swap(v);
	cout << "收缩后v的容量是:" << v.capacity() << endl;
	cout << "收缩后v的大小是:" << v.size() << endl;
}
int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}