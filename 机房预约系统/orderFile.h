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
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();
	//��¼ԤԼ����
	int mSize;
	//��¼����ԤԼ��¼������  key ��¼����,value �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> mOrderData;
};