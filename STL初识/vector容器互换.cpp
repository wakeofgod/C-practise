#include <iostream>
#include <vector>
#include <string>
using namespace std;

//vector��������
//����ʹ��

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
	cout << "������:" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
//ʵ����;
//����swap���������ռ�
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v��������:" << v.capacity() << endl;
	cout << "v�Ĵ�С��:" << v.size() << endl;
	v.resize(3);//����ָ����С
	cout << "�����ƶ���v��������:" << v.capacity() << endl;
	cout << "�����ƶ���v�Ĵ�С��:" << v.size() << endl;
	//����swap�����ڴ�
    //����һ���������󣬿���v��Ȼ���v����
	vector<int>(v).swap(v);
	cout << "������v��������:" << v.capacity() << endl;
	cout << "������v�Ĵ�С��:" << v.size() << endl;
}
int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}