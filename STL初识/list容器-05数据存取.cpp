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
	cout << "��һ��Ԫ����:" << L1.front() << endl;
	cout << "���һ��Ԫ����:" << L1.back() << endl;
	//��֤��������֧���������
	list<int>::iterator it = L1.begin();
	//����it++,��ֹit+1
	it++;
	//it = it + 1;
}
int main() {
	test01();
	system("pause");
	return 0;
}