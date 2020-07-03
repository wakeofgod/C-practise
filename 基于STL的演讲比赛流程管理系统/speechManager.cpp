#include "speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
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
	this->m_Index++;
	//2����

	//3��ʾ�������

	//�ڶ��ֱ���
	//1��ǩ

	//2����

	//3��ʾ���ս��

	//4�������
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
//�˳�ϵͳ
void SpeechManager:: exitSystem()
{
	cout << "******��ӭ�´�ʹ��******" << endl;
	system("pause");
	exit(0);
}