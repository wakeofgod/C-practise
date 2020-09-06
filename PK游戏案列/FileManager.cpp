#include "FileManager.h"

//解析单行数据
void FileManager::parseLineToVector(string firstLine, vector<string>&v)
{
	int pos = 0;
	int start = 0;
	while (true)
	{
		pos = firstLine.find(",", start);
		if (pos == -1)
		{
			//最后一个
			string temp = firstLine.substr(start, firstLine.size() - start);
			v.push_back(temp);
			break;
		}
		string temp = firstLine.substr(start, pos - start);
		v.push_back(temp);
		start = pos + 1;
	}
}
//加载csv文件格式
void FileManager::loadCSVData(string filepath, map<string, map<string, string>>&mFileData)
{
	//ifstream ifs("./Hero.csv");
	ifstream ifs(filepath);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	string firstLine;
	ifs >> firstLine;
	//cout << firstLine<<endl;
	vector<string>vFirst;
	parseLineToVector(firstLine, vFirst);
	//for (vector<string>::iterator it = v.begin();it != v.end();it++) 
	//{
	//	cout << *it << endl;
	//}
	//其他行数据
	//总容器
	//map<string, map<string, string>>mFileData;
	string data;
	while (ifs>>data)
	{
		map<string, string>mLineData;
		vector<string>vLineData;
		parseLineToVector(data, vLineData);
		for (int i = 0; i < vLineData.size(); i++)
		{
			mLineData.insert(make_pair(vFirst[i], vLineData[i]));
		}
		mFileData.insert(make_pair(vLineData[0], mLineData));
	}
}