#include <iostream>
#include <string>
#include <set>
using namespace std;

void printSet(const set<int> &s)
{
	for (set<int>::const_iterator i = s.begin(); i != s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;
	pair<set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}
	ret= s1.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}
	multiset<int>ms2;
	ms2.insert(10);
	ms2.insert(10);
	ms2.insert(10);
	for (multiset<int>::iterator i = ms2.begin(); i !=ms2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}