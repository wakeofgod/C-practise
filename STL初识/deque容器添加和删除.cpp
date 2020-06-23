#include <iostream>
#include <string>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it !=d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//¡Ω∂À≤Ÿ◊˜
void test01()
{
	deque<int>d1;
	//Œ≤≤Â
	d1.push_back(10);
	d1.push_back(20);
	//Õ∑≤Â
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//Œ≤…æ
	cout << "Œ≤…æ:";
	d1.pop_back();
	printDeque(d1);
	//Õ∑…æ
	d1.pop_front();
	cout << "Õ∑…æ:";
	printDeque(d1);
}
void test02()
{
	deque<int>d1;
	//Œ≤≤Â
	d1.push_back(10);
	d1.push_back(20);
	//Õ∑≤Â
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//insert≤Â»Î
	d1.insert(d1.begin(), 1000);
	printDeque(d1);
	d1.insert(d1.begin(), 2, 10000);
	printDeque(d1);
	//∞¥’’«¯º‰≤Â»Î
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);
}
void test03()
{
	deque<int>d1;
	//Œ≤≤Â
	d1.push_back(10);
	d1.push_back(20);
	//Õ∑≤Â
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//…æ≥˝
	d1.erase(d1.begin());
	printDeque(d1);
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);
	d1.erase(d1.begin(), d1.end());
	printDeque(d1);
}
int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}