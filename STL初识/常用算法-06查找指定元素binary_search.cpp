#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//binary_search ����ָ��Ԫ�أ�����������������ʹ��
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
	//������֮�����ֵ���ң������ܲ��ȶ�
	v.push_back(2);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret)
	{
		cout << "�ҵ�" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}
int main() {
	test01();
	system("pause");
	return 0;
}