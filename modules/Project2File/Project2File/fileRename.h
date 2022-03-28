#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class fileRename
{
public:
	fileRename();
	~fileRename();

	int fileProcess(string inputPath, string outputPath);
	int fileProcessTwo(string inputPathTwo, string outputPathTwo);
	int fileProcessThree(string inputPathThree, string outputPathThree);

private:

	void getFilesTest(string path, vector<string>& files);
	void getFilesFilter(string path, vector<string>& files, string Filter);

private:
	string strOriginalName;
	string strRename;
	string strLog;
};

