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
	//第一种
	m1.insert(pair<int, int>(1, 10));
	//第二种
	m1.insert(make_pair<int, int>(2, 20));
	//第三种
	m1.insert(map<int, int>::value_type(3, 30));
	//第四种,不建议用中括号插值,不存在的键值对打印的时候会自动添加空value的，一般用来访问元素 
	m1[4] = 40;
	printMap(m1);
	//删除
	//迭代器删除
	m1.erase(m1.begin());
	printMap(m1);
	//key删除
	m1.erase(3);
	printMap(m1);
}
int main() {
	test01();
	system("pause");
	return 0;
}