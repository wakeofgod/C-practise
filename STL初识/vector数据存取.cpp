#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//����[]��ʽ����Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	//����at��ʽ����Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��:"<<v1.front() << endl;

	cout <<"���һ��Ԫ��:"<< v1.back() << endl;
}
int main() {
	test01();

	system("pause");
	return 0;
}