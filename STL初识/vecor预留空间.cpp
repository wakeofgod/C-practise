#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test01()
{
	vector<int> v;
	int num=0;
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//���ָ�벻ָ���һ��Ԫ�أ����������ڶ�̬��չ
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}		
	}
	cout << "vector������̬��չ�Ĵ�����:" << num << endl;
}
void test02()
{
	vector<int> v;
	//ָ��Ԥ���ռ��С
	v.reserve(100000);
	int num = 0;
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		//���ָ�벻ָ���һ��Ԫ�أ����������ڶ�̬��չ
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "Ԥ���ռ��vector������̬��չ�Ĵ�����:" << num << endl;
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}