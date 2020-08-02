#include "orderFile.h"
#include <algorithm>
using namespace std;

//��ȡ�ַ���
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
//��ӡСmap
//void printSmallMap(pair<string,string> &p)
//{
//	//cout << str1 << " " << str2 << endl;
//	cout << p.first << " " << p.second << endl;
//}
void printSmallMap(map<string, string>::reference i)
{
	cout << i.first << " " << i.second << endl;
}
//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;		//����
	string interval;	//ʱ���
	string stuId;		//ѧ�����
	string stuName;		//ѧ������
	string roomId;		//�����
	string status;		//״̬

	this->mSize = 0;
	while (ifs>>date&&ifs>>interval
		&&ifs>>stuId&&ifs>>stuName
		&&ifs>>roomId&&ifs>>status)
	{
		//����
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
		//��ȡ����
		subStrOrder(&m, date);
		//��ȡʱ���
		subStrOrder(&m, interval);
		//��ȡѧ��
		subStrOrder(&m, stuId);
		//��ȡ����
		subStrOrder(&m, stuName);
		//��ȡ������
		subStrOrder(&m, roomId);
		//��ȡ״̬
		subStrOrder(&m, status);
		//��ŵ�������
		this->mOrderData.insert(make_pair(this->mSize, m));
		this->mSize++;
	}
	ifs.close();
	//���Դ���
	for (map<int,map<string,string>>::iterator it = mOrderData.begin(); it!=mOrderData.end(); it++)
	{
		//���÷�װ��ӡСmapʧ��
		//for_each(it->second.begin(), it->second.end(), printSmallMap);
		cout << "��" << it->first << "����¼" << endl;
		for (map<string,string>::iterator it2 = it->second.begin(); it2 !=it->second.end(); it2++)
		{
			cout <<"key:"<< it2->first << " value: " << it2->second << endl;
		}
		cout << endl;
	}
}
//����ԤԼ��¼
void OrderFile::updateOrder()
{

}