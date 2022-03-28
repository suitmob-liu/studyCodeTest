#pragma once
/*
*��˵����ClassDebugרע�ڽ�������ӡ����
*����ӳ������־��ӡ�ȼ�����־��ӡ��Ӧ��ϵͳʱ�䣻��־���ݵ�
*/

#include "generalType.h"

class ClassDebug
{
private:
	ClassDebug();

public:
	~ClassDebug();
	//��ȡ���������ӿ�
	static ClassDebug& getInStance();
	//�����ַ���д����־�ļ�
	void debugLog(string& inputDebug, u16_t logLevel = 1);
	void debugLog(const char* inputChar, u16_t logLevel = 1);

private:
	//��ȡϵͳʱ�䣬��ǰ����Ϊ�룬������Ҫ�޸�Ϊ���뼶
	string getCurrentTime();

private:
	FILE* m_pFileLog;

};

