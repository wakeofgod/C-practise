#include <iostream>
#include <string>
using namespace std;

class MyAdd
{
public:
	int operator ()(int a, int b)
	{
		return a + b;
	}
};

//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}
//2.�������󳬳���ͨ�����ĸ���������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator ()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;
};
void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myprint���õĴ�����:" << myPrint.count << endl;
}
//3�������������Ϊ��������
void doPrint(MyPrint &mp, string test) 
{
	mp(test);
}
void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}
int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}