#include "workerManager.h"
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在的情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//文件存在，不为空
	int num = this->GetEmpNum();
	//cout << "职工人数为:" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据存放到数组中
	this->InitEmp();
	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout <<"职工编号"<< this->m_EmpArray[i]->m_Id<<"\t"
	//		<<"职工姓名"<< this->m_EmpArray[i]->m_Name << "\t" 
	//		<<"岗位"<< this->m_EmpArray[i]->m_DeptId<<endl;
	//}
}
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
void WorkerManager::ShowMenu() 
{
	cout << "******************************" << endl;
	cout << "*****欢迎使用职工管理系统*****" << endl;
	cout << "********0.退出管理系统********" << endl;
	cout << "********1.增加职工信息********" << endl;
	cout << "********2.显示职工信息********" << endl;
	cout << "********3.删除职工信息********" << endl;
	cout << "********4.修改职工信息********" << endl;
	cout << "********5.查找职工信息********" << endl;
	cout << "********6.按照编号排序********" << endl;
	cout << "********7.清空所有文档********" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp() {
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0) {
		//计算新添加空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker ** newSpace= new Worker*[newSize];
		//将原来的数据拷贝到新空间下
		if (this->m_EmpArray != NULL) 
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入" << i + 1 << "个新员工的编号" << endl;
			cin >> id;
			cout << "请输入" << i + 1 << "个新员工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存在数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有的空间
		delete[]this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新员工" << endl;
		//保存数据到文件中
		this->Save();
	}
	else {
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int WorkerManager::GetEmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid) 
	{
		num++;
	}
	return num;
}
void WorkerManager::InitEmp() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>deptid)
	{
		Worker *worker = NULL;
		if (deptid == 1) 
		{
			worker = new Employee(id, name, 1);
		}
		else if (deptid == 2) 
		{
			worker = new Manager(id, name, 2);
		}
		else 
		{
			worker = new Boss(id, name, 3);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::ShowEmp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum ; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//
	system("pause");
	system("cls");
}

void WorkerManager::DelEmp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else 
	{
		cout << "请输入要删除的员工编号" << endl;
		int id = 0;
		cin >> id;
		int index= this->IsExsit(id);
		//说明改职工存在
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组人数
			this->m_EmpNum--;
			//数组更新到文件中
			this->Save();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
		system("pause");
		system("cls");
	} 
}

int WorkerManager::IsExsit(int id) 
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::ModifyEmp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExsit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid;
			string newName;
			int dSelect = 0;
			cout << "查到" << id << "号职工，请输入新职工编号" << endl;
			cin >> newid;
			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newid, newName, 1);
				break;
			case 2:
				worker = new Manager(newid, newName, 2);
				break;
			case 3:
				worker = new Boss(newid, newName, 3);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功!" << endl;
			//保存到文件中
			this->Save();
		}
		else
		{
			cout << "找不到该员工，删除失败" << endl;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入要查找的员工编号" << endl;
			int id;
			cin >> id;
			int ret = this->IsExsit(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl; 
			}
		}
		else if (select == 2) 
		{
			string name;
			cout << "请输入查找的姓名:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功!该职工信息如下:" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;
		int select = 0;
		cin >> select;
		//选择排序
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) 
					{
						minOrMax = j;
					}
				}
				else if (select == 2)//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//判断一开始认定的最小最大值是不是计算后的最小最大值
			if (i != minOrMax)
			{
				Worker *temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功!排序后结果为:" << endl;
		this->Save();
		this->ShowEmp();
	}
}

void WorkerManager::CleanFile()
{
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区的数组指针
			delete this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功!" << endl;
	}
	system("pause");
	system("cls");
}