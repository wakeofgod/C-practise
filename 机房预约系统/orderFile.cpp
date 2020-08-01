#include "orderFile.h"
#include <algorithm>
using namespace std;

//截取字符串
void subStrOrder(map<string, string>* m, string  &keyValue)
{
	int pos = keyValue.find(":");
	string key;
	string value;
	if (pos != -1)
	{
		key = keyValue.substr(0, pos);
		value = keyValue.substr(pos + 1, keyValue.size() - pos - 1);
		m->insert(make_pair(key, value));
	}
}
//打印小map
void printSmallMap(pair<string,string> &p)
{
	//cout << str1 << " " << str2 << endl;
	cout << p.first << " " << p.second << endl;
}
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;		//日期
	string interval;	//时间段
	string stuId;		//学生编号
	string stuName;		//学生姓名
	string roomId;		//房间号
	string status;		//状态

	this->mSize = 0;
	while (ifs>>date&&ifs>>interval
		&&ifs>>stuId&&ifs>>stuName
		&&ifs>>roomId&&ifs>>status)
	{
		//测试
		//cout << date << interval << stuId << stuName << roomId << status << endl;
		string key;
		string value;
		map<string, string>m;
		//int pos= date.find(":");
		//if (pos != -1)
		//{
		//	key = date.substr(0, pos);
		//	value = date.substr(pos + 1, date.size() - pos - 1);
		//	m.insert(make_pair(key, value));
		//}
		//截取日期
		subStrOrder(&m, date);
		//截取时间段
		subStrOrder(&m, interval);
		//截取学号
		subStrOrder(&m, stuId);
		//截取姓名
		subStrOrder(&m, stuName);
		//截取机房号
		subStrOrder(&m, roomId);
		//截取状态
		subStrOrder(&m, status);
		//存放到大容器
		this->mOrderData.insert(make_pair(this->mSize, m));
		this->mSize++;
	}
	ifs.close();
	//测试代码
	for (map<int,map<string,string>>::iterator it = mOrderData.begin(); it!=mOrderData.end(); it++)
	{
		//调用封装打印小map失败
		//for_each(it->second.begin(), it->second.end(), printSmallMap);
		cout << "第" << it->first << "条记录" << endl;
		for (map<string,string>::iterator it2 = it->second.begin(); it2 !=it->second.end(); it2++)
		{
			cout <<"key:"<< it2->first << " value: " << it2->second << endl;
		}
		cout << endl;
	}
}
//更新预约记录
void OrderFile::updateOrder()
{

}