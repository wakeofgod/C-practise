#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
//�º��� ����ֵ������bool���ͣ���Ϊν��
//һԪν��
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
	//��������,��û�д���5 ������
	//ʹ����������GreaterFive()
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it != v.end())
	{
		//cout << "�ҵ���" << *it << endl;
		for (; it != v.end(); it++)
		{
			cout << "�ҵ���" << *it << endl;
		}
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