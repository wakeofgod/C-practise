#include <iostream>
#include <string>
using namespace std;

void test01()
{
	//��һ�ִ�����ʽ
	pair<string, int>p1("Tom", 20);
	cout << "������" << p1.first << "\t����:" << p1.second << endl;
	//�ڶ��ִ�����ʽ
	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "������" << p2.first << "\t����:" << p2.second << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}