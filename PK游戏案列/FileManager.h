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
	//������������
	void parseLineToVector(string line,vector<string>&v);
	//����csv�ļ���ʽ
	void loadCSVData(string filepath,map<string,map<string,string>>&m);
};
