#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//≥£”√sort≈≈–Ú
//sort 
void myPrint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	//Ωµ–Ú
	sort(v.begin(), v.end(), greater<int>());
	cout << "Ωµ–Ú" << endl;
	for_each(v.begin(), v.end(), myPrint);
}
int main() {
	test01();
	system("pause");
	return 0;
}