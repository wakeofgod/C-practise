#include <iostream>
#include <string>
#include <numeric>
#include <vector>
using namespace std;

void test01()
{
	vector<int>v1;
	for (int i = 0; i <=100; i++)
	{
		v1.push_back(i);
	}
	int total = accumulate(v1.begin(), v1.end(), 0);
	cout << "×ÜºÍÊÇ" << total << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}