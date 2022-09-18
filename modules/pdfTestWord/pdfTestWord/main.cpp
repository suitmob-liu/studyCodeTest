
#include "ClassTestA.h"

int main(void)
{
    std::string inPath;
    std::cout << "输入待转换的文件：";
    std::cin >> inPath;
    std::cout << std::endl;
    ClassTestA A;
    A.testOne(inPath);

    std::cout << "finish" << std::endl;

    system("Pause");
    return 0;
}