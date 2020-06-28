#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include <ctime>

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//random_shuffleËæ»ú´òÂÒË³Ðò
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}
int main() {
	srand((unsigned int)time(NULL));
	test01();
	system("pause");
	return 0;
}