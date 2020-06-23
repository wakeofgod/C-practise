#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

//部门
#define  CEHUA 0
#define  MEISHU 1
#define  YANFA 2
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;
		//将员工放入容器
		v.push_back(worker);
	}
}
void printWorker(vector<Worker> &v)
{
	for (vector<Worker>::iterator i = v.begin(); i !=v.end(); i++)
	{
		cout << "姓名:" << i->m_Name << "\t 薪水:" << i->m_Salary << endl;
	}
	cout << endl;
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator i = v.begin(); i !=v.end(); i++)
	{
		//生成随机部门编号 0 1 2
		int deptId = rand() % 3;
		//将员工分组
		m.insert(make_pair(deptId, *i));
	}
}
void showWorkerByGroup(multimap<int,Worker> &m)
{
	cout << "策划部门:" << endl;

	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (;pos!=m.end()&&index<count; pos++, index++)
	{
		cout << "姓名:" << pos->second.m_Name << "\t 薪水" << pos->second.m_Salary << endl;
	}
	cout << "=================="<<endl;
	cout << "美术部门" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (;pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名:" << pos->second.m_Name << "\t 薪水" << pos->second.m_Salary << endl;
	}
	cout << "==================" << endl;
	cout << "研发部门" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (;pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名:" << pos->second.m_Name << "\t 薪水" << pos->second.m_Salary << endl;
	}
}
int main() {
	//随机数种子
	srand((unsigned int)time(NULL));
	//1创建员工
	vector<Worker>vWorker;
	createWorker(vWorker);
	
	printWorker(vWorker);
	//2随机分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker,mWorker);
	//3分组显示员工
	showWorkerByGroup(mWorker);
	system("pause");
	return 0;
}