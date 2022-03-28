#pragma once

#include <string>

using std::string;

class TypeConversion
{
private:
	char* pointer_int2char = nullptr;
	string* pointer_int2string = nullptr;

public:
	char* int2char(int target)
	{
		delete[] pointer_int2char;

		int target_absolute = target;
		bool sign = 0;//正负号,为false表示正数，为true表示负数。将true设为负数有很多原因，比方说，是负数就要进行很多附加的操作
		if (target < 0)
		{
			sign = true;
			target_absolute *= -1;//取绝对值
		}

		int digit = 0;//获得该字符的位数
		int target_abs_dup = target_absolute;//target_abs_dup：target absolute duplicate 目标绝对值的副本

		/*之所以设置这个循环，是因为使用求模的方法只能从目标的个位数开始获得，
		**这里不打算使用栈，所以这里进行了一些处理，先获得目标的位数.
		**这是为了后面创建合适大小的数组*/
		do
		{
			target_abs_dup /= 10;
			digit++;
		} while (target_abs_dup);

		char* bit_array = new char[digit + sign + 1];
		if (sign)
			bit_array[0] = '-';//如果目标是负数，在字符串前面加一个负号
		bit_array[digit + sign] = '\0';//将该数组设置为字符串
		for (int bit = digit + sign - 1, target_abs_dup = target_absolute; bit >= sign; --bit)//低位放到数组的后面
		{
			bit_array[bit] = target_abs_dup % 10 + '0';//加字符0是为了将个位数int值转换为单个char字符
			target_abs_dup /= 10;
		}

		this->pointer_int2char = bit_array;

		return this->pointer_int2char;
	}

	string& int2string(int target)//也可以使用C++11增加的方法to_string来代替使用此方法
	{
		delete[] pointer_int2string;

		string* p_result = new string;
		this->pointer_int2string = p_result;
		*p_result = "";//初始化

		char* int2char_backup = this->pointer_int2char;//备份int2char方法中的数据
		this->pointer_int2char = nullptr;

		*p_result += this->int2char(target);

		this->pointer_int2char = int2char_backup;//恢复int2char方法中的数据

		return *p_result;
	}

public:
	TypeConversion() {}

	~TypeConversion()//此析构函数也允许手动调用
	{
		delete[] pointer_int2char;
		this->pointer_int2char = nullptr;

		delete pointer_int2string;
		this->pointer_int2string = nullptr;
	}

};
