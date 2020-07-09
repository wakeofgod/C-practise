#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include "speechManager.h"
#include <ctime>
int main() {
	//�����������
	SpeechManager sm;
	//����������
	srand((unsigned int)time(NULL));
#pragma region ���Դ���
	for (map<int,Speaker>::iterator it = sm.m_Speaker.begin(); it!=sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ��" << it->first
			<< "\tѡ������:" << it->second.m_Name
			<< "\t�ɼ�:" << it->second.m_Score[0] << endl;
	}
#pragma endregion

	int choice = 0;
	while (true)
	{
		sm.showMenu();
		cout << "���������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			sm.showRecord();
			break;
		case 3://��ռ�¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
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