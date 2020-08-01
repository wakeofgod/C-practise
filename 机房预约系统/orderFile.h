#pragma once
#include <iostream>
#include <string>
#include "globalFile.h"
#include <fstream>
#include <map>

using namespace std;

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();
	//记录预约条数
	int mSize;
	//记录所有预约记录的容器  key 记录条数,value 具体记录的键值对信息
	map<int, map<string, string>> mOrderData;
};