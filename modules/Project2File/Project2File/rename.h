#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <io.h>

#include "type_conversion.h"

namespace basic_namespace
{
	using std::stringstream;
	using std::string;
	using std::vector;

	using std::cin;
	using std::cout;
	using std::endl;
}

namespace rename_mode
{
	using namespace basic_namespace;

	//模式1：直接修改名称（只保留前面的文件路径的部分）。insert_context是有用部分在修改之后的名称
	string edit_name1(string old_name, string old_suffix, string new_suffix, string insert_context)
	{
		for (int i = old_name.length() - 1, j = old_suffix.length() - 1;
			i > -1 && j > -1; --i, --j)
		{
			if (old_name[i] != old_suffix[j])
				return "";//如果提供不正确的后缀，将返回空串
		}

		if ('.' != old_name[old_name.length() - old_suffix.length() - 1])
			return "";//如果没有找到点号，直接返回空串

		int signal = old_name.length() - 1;
		while (signal > -1)//寻找地址与实际内容之间的界限
			if (old_name[--signal] == '\\')
				break;

		//substr的第一个参数数组下标起点值，第二个参数是拷贝的字符数，而不是终点值
		string postfix = old_name.substr(0, signal + 1);//获取文件名的地址部分

		old_name = postfix + insert_context + "." + new_suffix;

		return old_name;
	}

	//该函数将删除有用部分的前useful_location个字符。insert_context是需要在有用部分前端要插入的内容
	string edit_name2(string old_name, string old_suffix, string new_suffix, string insert_context, int useful_location)
	{//useful_location为有用位置处的数组下标
		for (int i = old_name.length() - 1, j = old_suffix.length() - 1;
			i > -1 && j > -1; --i, --j)
		{
			if (old_name[i] != old_suffix[j])
				return "";//如果提供不正确的后缀，将返回空串
		}

		if ('.' != old_name[old_name.length() - old_suffix.length() - 1])
			return "";//如果没有找到点号，直接返回空串

		int kk = 0;

		int signal = old_name.length() - 1;
		while (signal > -1)//寻找地址与实际内容之间的界限
			if (old_name[--signal] == '\\')
				break;

		int actual_content_num = old_name.length() - old_suffix.length() - 1;//文件名中除后缀、点号之外实际内容的字符数

		//substr的第一个参数数组下标起点值，第二个参数是拷贝的字符数，而不是终点值
		string postfix = old_name.substr(0, signal + 1);//获取文件名的地址部分

		//获取文件名的有用部分的内容
		string real_content = old_name.substr(signal + 1 + useful_location, actual_content_num - (signal + 1 + useful_location));

		old_name = postfix + insert_context + real_content + "." + new_suffix;

		return old_name;
	}

}

namespace file_rename
{
	using namespace basic_namespace;
	using namespace rename_mode;

	void getFiles(string path, vector<string>& files)//此函数来源于网上，几乎未加删改
	{
		//文件句柄
		intptr_t   hFile = 0;

		//文件信息
		_finddata_t fileinfo;
		string temp;
		if ((hFile = _findfirst(temp.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
		{
			do
			{
				//如果是目录,迭代之
				//如果不是,加入列表
				if ((fileinfo.attrib & _A_SUBDIR))
				{
					if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
						getFiles(temp.assign(path).append("\\").append(fileinfo.name), files);
				}//此处如果没有大括号，编译器会混淆这里两个if与下面的else之间的关系
				else//美观起见，上面使用了大括号，这里也使用大括号好了
				{
					files.push_back(temp.assign(path).append("\\").append(fileinfo.name));
				}
			} while (_findnext(hFile, &fileinfo) == 0);
			_findclose(hFile);
		}
	}

	//此函数用于简单的名称修改：在给定的名称后面加递增的编号。begin_order是起始编号，默认为1
	bool modify_name1(string file_path, string old_suffix, string new_suffix, string insert_context, int begin_order = 1)
	{//此函数要和 edit_name1配对使用
		vector<string> files;
		getFiles(file_path.data(), files);
		for (int order = 0, file_num = files.size(); order < file_num; ++order)
		{
			/*这是为了后面使用TypeConversion类的int转string方法而创建的对象。
			考虑到C++中的持续性规则，最好不要创建该类的匿名对象*/
			TypeConversion temp;
			string new_name = edit_name1(files[order], old_suffix, new_suffix,
				insert_context + temp.int2string(begin_order + order));//获得按要求编辑好的名称

			if (0 == new_name.length())
			{
				cout << "新名称不合法：" << endl << new_name << endl;
				continue;
			}

			if (rename(files[order].data(), new_name.data()))
				cout << "失败：" << endl << files[order] << endl;
			else
				cout << "成功：" << endl << files[order] << endl;

		}

		return true;//此函数的返回值尚未投入使用，现在直接设置成 true
	}

	//此函数用于在所有的文件名中删除有用部分的前useful_location个字符，
	//并在有用部分的前端插入一段相同的内容。
	bool modify_name2(string file_path, string old_suffix, string new_suffix, string insert_context, int useful_location = 0)
	{//此函数要和 edit_name2配对使用
		vector<string> files;
		getFiles(file_path.data(), files);
		for (int order = 0, file_num = files.size(); order < file_num; ++order)
		{
			string new_name = edit_name2(files[order], old_suffix, new_suffix,
				insert_context, useful_location);//获得按要求编辑好的名称

			if (0 == new_name.length())
			{
				cout << "新名称不合法：" << endl << new_name << endl;
				continue;
			}

			if (rename(files[order].data(), new_name.data()))
				cout << "失败：" << endl << files[order] << endl;
			else
				cout << "成功：" << endl << files[order] << endl;

		}

		return true;//此函数的返回值尚未投入使用，现在直接设置成 true
	}

}


