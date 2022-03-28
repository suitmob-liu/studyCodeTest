#include <io.h>
#include <Windows.h>

#include "fileRename.h"
#include "ClassDebug.h"
#include "rename.h"
//#include "dirent.h"

#pragma warning(disable:4996)

using namespace file_rename;

fileRename::fileRename()
{
}

fileRename::~fileRename()
{
	ClassDebug& nDebug = ClassDebug::getInStance();
	strLog = "process end!\n";
	nDebug.debugLog(strLog);
}

int fileRename::fileProcess(string inputPath, string outputPath)
{
	ClassDebug& nDebug = ClassDebug::getInStance();
	strLog = "process begin!";
	nDebug.debugLog(strLog);
	int ret = 0;

	if(inputPath == outputPath)
	{
		strLog = "inpath equal outpath is illegal!";
		nDebug.debugLog(strLog);
		return -1;
	}

	vector<string> vecFileName;
	bool fileAlready = false;
	string filter = "pcm";
	getFilesFilter(inputPath, vecFileName, filter);
	if (vecFileName.size() != 0)
	{
		fileAlready = true;
	}
	if (!fileAlready)
	{
		filter = "wav";
		getFilesFilter(inputPath, vecFileName, filter);
	}

	if (vecFileName.size() == 0)
	{
		strLog = "not find any file!";
		nDebug.debugLog(strLog);
		return 2;
	}

	for (int i = 0; i < vecFileName.size(); i++)
	{
		strLog = "original file is ";
		strLog += vecFileName[i];

		strOriginalName = vecFileName[i];
		strRename = outputPath;
		strRename += "\\outputFile_";
		strRename += to_string(i+1);
		if (fileAlready)
		{
			strRename += ".pcm";
		}
		else
		{
			strRename += ".wav";
		}

		ret = rename(strOriginalName.c_str(), strRename.c_str());
		if (ret != 0)
		{
			strLog = "rename failure and ret ";
			strLog += to_string(ret);
			nDebug.debugLog(strLog);
			return -1;
		}
		strLog += " and rename is ";
		strLog += strRename;
		nDebug.debugLog(strLog);
	}
	return 0;
}

int fileRename::fileProcessTwo(string inputPathTwo, string outputPathTwo)
{
	string file_path = inputPathTwo;//待修改文件所在的文件夹路径

	string old_suffix = "pcm";//存放旧后缀的字符串，不带最开始的点号
	string new_suffix = "pcm";//存放新后缀的字符串，不带最开始的点号
	string insert_context = "outputFile_";

	modify_name1(file_path, old_suffix, new_suffix, insert_context);

	return 0;
}

int fileRename::fileProcessThree(string inputPathThree, string outputPathThree)
{
	//DIR* directory = opendir(inputPathThree.c_str());
	//struct dirent* direntStruct;
	//
	//if (directory != NULL)
	//{
	//	while (direntStruct = readdir(directory))
	//	{
	//		printf("File Name: %s\n", direntStruct->d_name);
	//	}
	//}

	return 0;
}


void fileRename::getFilesTest(string path, vector<string>& files)
{
	//文件句柄
	intptr_t   hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFilesTest(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void fileRename::getFilesFilter(string path, vector<string>& files, string Filter)
{
	//文件句柄
	intptr_t   hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	char temp[100] = { 0 };
	sprintf(temp, "\\*.%s", Filter.c_str());
	if ((hFile = _findfirst(p.assign(path).append(temp).c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFilesTest(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
