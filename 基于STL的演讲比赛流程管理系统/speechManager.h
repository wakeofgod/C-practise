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
	//���캯��
	SpeechManager();
	//����ѡ������ 12��
	vector<int> v1;
	//��һ�ֽ������� 6��
	vector<int> v2;
	//ʤ��ǰ�������� 3��
	vector<int> vVictory;
	//��ű�� �Լ���Ӧ�ľ���ѡ�ֵ�����
	map<int, Speaker>m_Speaker;
	//��¼��������
	int m_Index;

	//��ʼ������
	void initSpeech();
	//��ʼ������12��ѡ��
	void createSpeaker();

	//չʾ�˵�
	void showMenu();
	//��ʼ���� -�������̵Ŀ���
	void startSpeech();
	//����
	void speechContest();
	//��ʾ������Ա��������
	void showScore();
	//��ǩ
	void speechDraw();
	//�������
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//�ļ�Ϊ�յı�ʶ
	bool fileIsEmpty;
	//�����¼
	map<int, vector<string>>m_Record;
	//��ʾ����÷�
	void showRecord();
	//�������
	void clearRecord();
	// �˳�
	void exitSystem();
	//��������
	~SpeechManager();
};