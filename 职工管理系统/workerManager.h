#pragma once //��ֹͷ�ļ��ظ�����
//�����ฺ������ݣ��û��˵���ͨ����ɾ�Ĳ飬�ļ���д
#include <iostream>
using namespace std;
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#define FILENAME "empFile.txt"
class WorkerManager 
{
public:
	WorkerManager();
	//չʾ�˵�
	void ShowMenu();
	//�˳�ϵͳ
	void ExitSystem();
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray;
	//���ְ��
	void AddEmp();
	//�����ļ�
	void Save();
	//�ж��ļ�
	bool m_FileIsEmpty;
	//ͳ���ļ��е�����
	int GetEmpNum();
	//��ʼ��Ա��
	void InitEmp();
	//��ʾԱ��
	void ShowEmp();
	//ɾ��Ա��
	void DelEmp();
	//�ж�Ա���Ƿ����
	int IsExsit(int id);
	//�޸�Ա��
	void ModifyEmp();
	//����Ա��
	void FindEmp();
	//Ա������
	void SortEmp();
	//����ļ�
	void CleanFile();
	~WorkerManager();
};