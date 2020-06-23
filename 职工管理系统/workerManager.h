#pragma once //防止头文件重复包含
//管理类负责的内容：用户菜单沟通，增删改查，文件读写
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
	//展示菜单
	void ShowMenu();
	//退出系统
	void ExitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray;
	//添加职工
	void AddEmp();
	//保存文件
	void Save();
	//判断文件
	bool m_FileIsEmpty;
	//统计文件中的人数
	int GetEmpNum();
	//初始化员工
	void InitEmp();
	//显示员工
	void ShowEmp();
	//删除员工
	void DelEmp();
	//判断员工是否存在
	int IsExsit(int id);
	//修改员工
	void ModifyEmp();
	//查找员工
	void FindEmp();
	//员工排序
	void SortEmp();
	//清空文件
	void CleanFile();
	~WorkerManager();
};