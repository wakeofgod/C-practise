#include "speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	//������ʷ�ɼ�
	this->loadRecord();
}
//��������
SpeechManager:: ~SpeechManager()
{

}
//��ʼ������
void SpeechManager::initSpeech() 
{
	//��֤����Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;
	//��ռ�¼����
	this->m_Record.clear();
}
//��ʼ������12��ѡ��
void SpeechManager:: createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
//չʾ�˵�
void SpeechManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "**********��ӭ�μ��ݽ�����**********" << endl;
	cout << "**********1.��ʼ�ݽ�����**********" << endl;
	cout << "**********2.�鿴�����¼**********" << endl;
	cout << "**********3.��ձ�����¼**********" << endl;
	cout << "**********0.�˳���������**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
//��ʼ���� -�������̵Ŀ���
void SpeechManager:: startSpeech()
{
	//��һ�ֱ���
	//1��ǩ
	this->speechDraw();
	//2����
	this->speechContest();
	//3��ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->m_Index++;
	//1��ǩ
	this->speechDraw();
	//2����
	this->speechContest();
	//3��ʾ���ս��
	this->showScore();
	//4�������
	this->saveRecord();
	//���ñ�������ȡ��¼
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "����������" << endl;
	system("pause");
	system("cls");
}
//��ǩ
void SpeechManager:: speechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------" << endl;
	cout << "��ǩ���ݽ�˳������" << endl;
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
//����
void SpeechManager:: speechContest()
{
	cout << "-----------------��" << this->m_Index << "�ֱ�����ʽ��ʼ:----------------" << endl;

	vector<int>v_Src;		//��������Ա����
	//׼����ʱ���������С��ĳɼ�
	multimap<double, int, greater<double>> groupScore;
	int num = 0;//��¼��Ա������6��һ��
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it !=v_Src.end(); it++)
	{
		num++;
		//cout <<"���:"<<*it<<"\t"<< this->m_Speaker[*it].m_Name << ":\t";
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			//rand()���0-400����������600�ڳ���10������ȡֵ60-100��������С��
			double score = (rand() % 401 + 600) / 10.0f;
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//��������
		d.pop_front();//�������У�ȥ����߷�
		d.pop_back();  //ȥ����ͷ�
		//���ܷ֣�Ȼ����ƽ��ֵ
		double sum = accumulate(d.begin(), d.end(), 0.0f);//�ܷ�
		double avg = sum / (double)d.size();			  //ƽ����
		//��ӡƽ����
		//cout << "\tƽ����:" << avg<<endl;
		//��ƽ���ַ�������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//��ŵ���ʱ������
		groupScore.insert(make_pair(avg, *it));
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С�������������:" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it!=groupScore.end(); it++)
			{
				cout << "���:\t"<<it->second<<"����:\t"<<m_Speaker[it->second].m_Name
					<<"�ɼ�:"<< m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
			}
			//ȡ��ǰ�������ŵ���һ��������
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
			//С���������
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "-----------------------��" << this->m_Index << "�ֱ������-----------------" << endl;
	system("pause");
}
//��ʾ������Ա��������
void SpeechManager:: showScore()
{
	cout << "��" << this->m_Index << "�ֽ���ѡ����Ϣ����:" << endl;
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
		cout << "ѡ�ֱ��:" << *it << "\t����:" << m_Speaker[*it].m_Name
			<< "\t�÷�:" << m_Speaker[*it].m_Score[this->m_Index-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}
//�������
void SpeechManager:: saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
	for (vector<int>::iterator it = vVictory.begin(); it!=vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs<<endl;
	//�ر�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	//����״̬
	this->fileIsEmpty = false;
}
//��ȡ��¼
void SpeechManager:: loadRecord()
{
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ���յ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ� �Ż���

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;;
		vector<string>v; //���6���ַ���
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
	//���Դ���
	//for (map<int,vector<string>>::iterator it = m_Record.begin(); it!=m_Record.end(); it++)
	//{
	//	cout << it->first << "�ھ����:" << it->second[0] << "\t����:" << it->second[1]
	//		<<"\t�Ǿ����:"<<it->second[2]<<"\t����:"<<it->second[3]
	//		<< "\t�������:" << it->second[4] << "\t����:" << it->second[5] << endl;
	//}
}
//��ʾ����÷�
void SpeechManager:: showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��"
				<< "�ھ����:" << this->m_Record[i][0] << "�÷�:" << this->m_Record[i][1] << " "
				<< "�Ǿ����:" << this->m_Record[i][2] << "�÷�:" << this->m_Record[i][3] << " "
				<< "�������:" << this->m_Record[i][4] << "�÷�:" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
//�������
void SpeechManager:: clearRecord()
{
	cout << "ȷ�����?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ,������ھ�ɾ�����´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//���»�ȡ��¼
		this->loadRecord();
		cout << "��ճɹ�!" << endl;
	}
	system("pause");
	system("cls");
}
//�˳�ϵͳ
void SpeechManager:: exitSystem()
{
	cout << "******��ӭ�´�ʹ��******" << endl;
	system("pause");
	exit(0);
}