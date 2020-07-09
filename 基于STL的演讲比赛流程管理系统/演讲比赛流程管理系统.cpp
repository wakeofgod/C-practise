#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include "speechManager.h"
#include <ctime>
int main() {
	//创建管理对象
	SpeechManager sm;
	//添加随机种子
	srand((unsigned int)time(NULL));
#pragma region 测试代码
	for (map<int,Speaker>::iterator it = sm.m_Speaker.begin(); it!=sm.m_Speaker.end(); it++)
	{
		cout << "选手编号" << it->first
			<< "\t选手姓名:" << it->second.m_Name
			<< "\t成绩:" << it->second.m_Score[0] << endl;
	}
#pragma endregion

	int choice = 0;
	while (true)
	{
		sm.showMenu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看记录
			sm.showRecord();
			break;
		case 3://清空记录
			sm.clearRecord();
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}