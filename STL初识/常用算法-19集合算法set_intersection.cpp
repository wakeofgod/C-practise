#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int> v1;
	vector<int>v2;
	//ԭ������������������
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vTarget;
	//Ŀ��������Ҫ�������ռ�
	//���������������������С���������ٿռ䣬ȡֵС������size����
	vTarget.resize(min(v1.size(), v2.size()));
	//��ȡ����
	vector<int>::iterator itEnd= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	cout << "��ʾ��������" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint());
	cout << endl;
	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}