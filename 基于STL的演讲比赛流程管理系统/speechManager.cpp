#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	//加载历史成绩
	this->loadRecord();
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
	//清空记录容器
	this->m_Record.clear();
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
	//2比赛
	this->speechContest();
	//3显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_Index++;
	//1抽签
	this->speechDraw();
	//2比赛
	this->speechContest();
	//3显示最终结果
	this->showScore();
	//4保存分数
	this->saveRecord();
	//重置比赛，获取记录
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
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
//比赛
void SpeechManager:: speechContest()
{
	cout << "-----------------第" << this->m_Index << "轮比赛正式开始:----------------" << endl;

	vector<int>v_Src;		//比赛的人员容器
	//准备临时的容器存放小组的成绩
	multimap<double, int, greater<double>> groupScore;
	int num = 0;//记录人员个数，6人一组
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it !=v_Src.end(); it++)
	{
		num++;
		//cout <<"编号:"<<*it<<"\t"<< this->m_Speaker[*it].m_Name << ":\t";
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			//rand()随机0-400的数，加上600在除以10，就是取值60-100区间的随机小数
			double score = (rand() % 401 + 600) / 10.0f;
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//降序排序
		d.pop_front();//降序排列，去除最高分
		d.pop_back();  //去除最低分
		//求总分，然后求平均值
		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
		double avg = sum / (double)d.size();			  //平均分
		//打印平均分
		//cout << "\t平均分:" << avg<<endl;
		//将平均分放入容器
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//存放到临时容器中
		groupScore.insert(make_pair(avg, *it));
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次如下:" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it!=groupScore.end(); it++)
			{
				cout << "编号:\t"<<it->second<<"姓名:\t"<<m_Speaker[it->second].m_Name
					<<"成绩:"<< m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
			}
			//取走前三名，放到下一个容器中
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			//小组容器清空
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "-----------------------第" << this->m_Index << "轮比赛完毕-----------------" << endl;
	system("pause");
}
//显示晋级人员比赛分数
void SpeechManager:: showScore()
{
	cout << "第" << this->m_Index << "轮晋级选手信息如下:" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it !=v.end(); it++)
	{
		cout << "选手编号:" << *it << "\t姓名:" << m_Speaker[*it].m_Name
			<< "\t得分:" << m_Speaker[*it].m_Score[this->m_Index-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}
//保存分数
void SpeechManager:: saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件
	for (vector<int>::iterator it = vVictory.begin(); it!=vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs<<endl;
	//关闭
	ofs.close();
	cout << "记录已经保存" << endl;
	//更改状态
	this->fileIsEmpty = false;
}
//读取记录
void SpeechManager:: loadRecord()
{
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//文件清空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符 放回来

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;;
		vector<string>v; //存放6个字符串
		int start = 0;
		int pos = -1;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			else
			{
				string temp = data.substr(start, pos - start);
				//cout << temp << endl;
				v.push_back(temp);
				start = pos + 1;
			}
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//测试代码
	//for (map<int,vector<string>>::iterator it = m_Record.begin(); it!=m_Record.end(); it++)
	//{
	//	cout << it->first << "冠军编号:" << it->second[0] << "\t分数:" << it->second[1]
	//		<<"\t亚军编号:"<<it->second[2]<<"\t分数:"<<it->second[3]
	//		<< "\t季军编号:" << it->second[4] << "\t分数:" << it->second[5] << endl;
	//}
}
//显示往届得分
void SpeechManager:: showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届"
				<< "冠军编号:" << this->m_Record[i][0] << "得分:" << this->m_Record[i][1] << " "
				<< "亚军编号:" << this->m_Record[i][2] << "得分:" << this->m_Record[i][3] << " "
				<< "季军编号:" << this->m_Record[i][4] << "得分:" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
//清空数据
void SpeechManager:: clearRecord()
{
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式,如果存在就删除重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();
		//重新获取记录
		this->loadRecord();
		cout << "清空成功!" << endl;
	}
	system("pause");
	system("cls");
}
//退出系统
void SpeechManager:: exitSystem()
{
	cout << "******欢迎下次使用******" << endl;
	system("pause");
	exit(0);
}