#include "workerManager.h"
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ���Ϊ��
	int num = this->GetEmpNum();
	//cout << "ְ������Ϊ:" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ��е����ݴ�ŵ�������
	this->InitEmp();
	//���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout <<"ְ�����"<< this->m_EmpArray[i]->m_Id<<"\t"
	//		<<"ְ������"<< this->m_EmpArray[i]->m_Name << "\t" 
	//		<<"��λ"<< this->m_EmpArray[i]->m_DeptId<<endl;
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
	cout << "*****��ӭʹ��ְ������ϵͳ*****" << endl;
	cout << "********0.�˳�����ϵͳ********" << endl;
	cout << "********1.����ְ����Ϣ********" << endl;
	cout << "********2.��ʾְ����Ϣ********" << endl;
	cout << "********3.ɾ��ְ����Ϣ********" << endl;
	cout << "********4.�޸�ְ����Ϣ********" << endl;
	cout << "********5.����ְ����Ϣ********" << endl;
	cout << "********6.���ձ������********" << endl;
	cout << "********7.��������ĵ�********" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp() {
	cout << "���������ְ������:" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0) {
		//��������ӿռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker ** newSpace= new Worker*[newSize];
		//��ԭ�������ݿ������¿ռ���
		if (this->m_EmpArray != NULL) 
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "������" << i + 1 << "����Ա���ı��" << endl;
			cin >> id;
			cout << "������" << i + 1 << "����Ա��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�룬������������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[]this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����Ա��" << endl;
		//�������ݵ��ļ���
		this->Save();
	}
	else {
		cout << "������������" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else 
	{
		cout << "������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;
		int index= this->IsExsit(id);
		//˵����ְ������
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//������������
			this->m_EmpNum--;
			//������µ��ļ���
			this->Save();
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա�����" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExsit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid;
			string newName;
			int dSelect = 0;
			cout << "�鵽" << id << "��ְ������������ְ�����" << endl;
			cin >> newid;
			cout << "������������:" << endl;
			cin >> newName;
			cout << "�������λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�!" << endl;
			//���浽�ļ���
			this->Save();
		}
		else
		{
			cout << "�Ҳ�����Ա����ɾ��ʧ��" << endl;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ���ҵ�Ա�����" << endl;
			int id;
			cin >> id;
			int ret = this->IsExsit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl; 
			}
		}
		else if (select == 2) 
		{
			string name;
			cout << "��������ҵ�����:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�!��ְ����Ϣ����:" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;
		int select = 0;
		cin >> select;
		//ѡ������
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) 
					{
						minOrMax = j;
					}
				}
				else if (select == 2)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶�����С���ֵ�ǲ��Ǽ�������С���ֵ
			if (i != minOrMax)
			{
				Worker *temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ�!�������Ϊ:" << endl;
		this->Save();
		this->ShowEmp();
	}
}

void WorkerManager::CleanFile()
{
	cout << "ȷ�����?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
			//ɾ������������ָ��
			delete this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�!" << endl;
	}
	system("pause");
	system("cls");
}