
#include "ClassTestA.h"

int main(void)
{
    std::string inPath;
    std::cout << "�����ת�����ļ���";
    std::cin >> inPath;
    std::cout << std::endl;
    ClassTestA A;
    A.testOne(inPath);

    std::cout << "finish" << std::endl;

    system("Pause");
    return 0;
}