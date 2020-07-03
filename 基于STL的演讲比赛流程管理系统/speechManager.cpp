#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
}
//析构函数
SpeechManager:: ~SpeechManager()
{

}
//初始化属性
void SpeechManager::initSpeech() 
{
	//保证容器为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	this->m_Index = 1;
}
//初始化创建12名选手
void SpeechManager:: createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		//12名选手编号
		this->v1.push_back(i + 10001);

		//选手编号以及对应的选手 存放到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
//展示菜单
void SpeechManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "**********欢迎参加演讲比赛**********" << endl;
	cout << "**********1.开始演讲比赛**********" << endl;
	cout << "**********2.查看往届记录**********" << endl;
	cout << "**********3.清空比赛记录**********" << endl;
	cout << "**********0.退出比赛程序**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
//开始比赛 -比赛流程的控制
void SpeechManager:: startSpeech()
{
	//第一轮比赛
	//1抽签
	this->speechDraw();
	this->m_Index++;
	//2比赛

	//3显示晋级结果

	//第二轮比赛
	//1抽签

	//2比赛

	//3显示最终结果

	//4保存分数
}
//抽签
void SpeechManager:: speechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "-------------------------" << endl;
	cout << "抽签后演讲顺序如下" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it!=v1.end(); it++)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
	system("pause");
	cout << endl;
}
//退出系统
void SpeechManager:: exitSystem()
{
	cout << "******欢迎下次使用******" << endl;
	system("pause");
	exit(0);
}