#include <iostream>
#include <string>
#include <map>
using namespace std;

void printMap(map<int, int> &m)
{
	for (map<int,int>::iterator i = m.begin(); i !=m.end(); i++)
	{
		cout << "key:" << i->first << "\t value:" << i->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int>m1;
	//��һ��
	m1.insert(pair<int, int>(1, 10));
	//�ڶ���
	m1.insert(make_pair<int, int>(2, 20));
	//������
	m1.insert(map<int, int>::value_type(3, 30));
	//������,�������������Ų�ֵ,�����ڵļ�ֵ�Դ�ӡ��ʱ����Զ���ӿ�value�ģ�һ����������Ԫ�� 
	m1[4] = 40;
	printMap(m1);
	//ɾ��
	//������ɾ��
	m1.erase(m1.begin());
	printMap(m1);
	//keyɾ��
	m1.erase(3);
	printMap(m1);
}
int main() {
	test01();
	system("pause");
	return 0;
}