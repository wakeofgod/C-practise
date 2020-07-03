#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <map>
#include "Speaker.h"

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
	//��ǩ
	void speechDraw();
	// �˳�
	void exitSystem();
	//��������
	~SpeechManager();
};