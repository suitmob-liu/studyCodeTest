#include <iostream>

#include "fileRename.h"

int main(void)
{
	int ret = 0;
	fileRename fr;
	string inpath = "D:\\CODE\\pcm";
	string outPath = "D:\\CODE\\pcm\\out";
	
	ret = fr.fileProcess(inpath, outPath);
	//ret = fr.fileProcessTwo(inpath, outPath);
	//ret = fr.fileProcessThree(inpath, outPath);
	if (ret != 0)
	{
		cout << "call fileProcess is failure!" << endl;
	}
	else
	{
		cout << "process success!" << endl;
	}

	system("Pause");

	return 0;
}