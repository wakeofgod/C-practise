#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <map>
#include <deque>
#include <numeric>
#include "Speaker.h"
#include <fstream>

class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//比赛选手容器 12人
	vector<int> v1;
	//第一轮晋级容器 6人
	vector<int> v2;
	//胜利前三名容器 3人
	vector<int> vVictory;
	//存放编号 以及对应的具体选手的容器
	map<int, Speaker>m_Speaker;
	//记录比赛轮数
	int m_Index;

	//初始化属性
	void initSpeech();
	//初始化创建12名选手
	void createSpeaker();

	//展示菜单
	void showMenu();
	//开始比赛 -比赛流程的控制
	void startSpeech();
	//比赛
	void speechContest();
	//显示晋级人员比赛分数
	void showScore();
	//抽签
	void speechDraw();
	//保存分数
	void saveRecord();
	//读取记录
	void loadRecord();
	//文件为空的标识
	bool fileIsEmpty;
	//往届记录
	map<int, vector<string>>m_Record;
	//显示往届得分
	void showRecord();
	//清空数据
	void clearRecord();
	// 退出
	void exitSystem();
	//析构函数
	~SpeechManager();
};