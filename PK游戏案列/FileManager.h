#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>
#include <map>
class FileManager
{
public:
	//解析单行数据
	void parseLineToVector(string line,vector<string>&v);
	//加载csv文件格式
	void loadCSVData(string filepath,map<string,map<string,string>>&m);
};
