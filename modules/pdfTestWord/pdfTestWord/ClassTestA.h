#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>

#pragma comment(lib, "../windows-x64/lib/Release/aspose_words_cloud_sdk.lib")

#include "aspose_words_cloud.h"

using namespace aspose::words::cloud;

class ClassTestA
{
public:
	void testOne(std::string& inPath);

private:
	std::string tranToGBK(const std::string& utf8_str);
};

