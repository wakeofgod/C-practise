#include <iostream>
#include <string>
#include <map>
using namespace std;

void printMap(const map<int, int> &m)
{
	for (map<int,int>::const_iterator i = m.begin(); i !=m.end(); i++)
	{
		cout << "key=" << i->first << "\t value=" << i->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int>m1;
	//map必须插入pair值，然后自动按照索引排序
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);
	
	map<int, int>m2(m1);
	printMap(m2);

	map<int, int>m3 = m2;
	printMap(m3);

}
int main() {
	test01();
	system("pause");
	return 0;
}