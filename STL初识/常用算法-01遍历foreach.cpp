#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>

//ÆÕÍ¨º¯Êý
void print01(int val)
{
	cout << val << " ";
}
//·Âº¯Êý
class Print02
{
public :
	void operator ()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), Print02());
	cout << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}