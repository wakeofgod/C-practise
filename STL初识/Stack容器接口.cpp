#include <iostream>
#include <stack>
#include <string>
using namespace std;

void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	//只要栈不为空，查看栈顶，并且执行出栈操作
	while (!s.empty())
	{
		cout << "栈顶元素:" << s.top() << endl;
		s.pop();
	}
	cout << "栈的大小:" << s.size() << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}
