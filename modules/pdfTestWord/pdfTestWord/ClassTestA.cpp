#include "ClassTestA.h"

#include <Windows.h>// π”√£∫MultiByteToWideChar

using namespace std;

void ClassTestA::testOne(std::string& inPath)
{
    std::string fileName = inPath;
    //auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
    auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"c76d9611-05e8-4ae4-8cd0-8672db1aa211", /*clientSecret*/ L"e9fe4db1c4f2da725b2e6a678791ad52");
    auto wordsApi = std::make_shared<api::WordsApi>(config);
    //std::wstring fileName = L"new.pdf";

    // Calls AcceptAllRevisionsOnline method for document in cloud.
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(fileName), std::istream::binary));
    std::shared_ptr< requests::AcceptAllRevisionsOnlineRequest > request(
        new requests::AcceptAllRevisionsOnlineRequest(
            requestDocument
        )
    );
    std::cout << "Calls AcceptAllRevisionsOnline method for document in cloud.end" << std::endl;

    auto acceptAllRevisionsOnlineResult = wordsApi->acceptAllRevisionsOnline(request);
    std::cout << "wordsApi->acceptAllRevisionsOnline.end" << std::endl;
    {
        char buffer[1024];
        std::ofstream fileWriter("test_result_new.docx", std::ofstream::binary);
        const auto& fileData = *acceptAllRevisionsOnlineResult->getDocument()->begin();
        std::cout << "*acceptAllRevisionsOnlineResult->getDocument()->begin() .end" << std::endl;
        std::string tempData;
        while (fileData.second->read(buffer, sizeof(buffer))) {
#if 0
            tempData = string(buffer);
            fileWriter.write(tempData.c_str(), tempData.size());
#else
            fileWriter.write(buffer, sizeof(buffer));
#endif
        }
        std::cout << "fileData.second->read .end" << std::endl;
        fileWriter.write(buffer, fileData.second->gcount());
        fileWriter.close();
    }
}

std::string ClassTestA::tranToGBK(const std::string& utf8_str)
{
    const char* src_str = utf8_str.c_str();
    int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, nullptr, 0);
    const std::size_t wsz_ansi_length = static_cast<std::size_t>(len) + 1;
    wchar_t* wsz_ansi = new wchar_t[wsz_ansi_length];
    memset(wsz_ansi, 0, sizeof(wsz_ansi[0]) * wsz_ansi_length);
    MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wsz_ansi, len);

    len = WideCharToMultiByte(CP_ACP, 0, wsz_ansi, -1, nullptr, 0, nullptr, nullptr);
    const std::size_t sz_ansi_length = static_cast<std::size_t>(len) + 1;
    char* sz_ansi = new char[sz_ansi_length];
    memset(sz_ansi, 0, sizeof(sz_ansi[0]) * sz_ansi_length);
    WideCharToMultiByte(CP_ACP, 0, wsz_ansi, -1, sz_ansi, len, nullptr, nullptr);
    std::string strTemp(sz_ansi);

    delete[] wsz_ansi;
    wsz_ansi = nullptr;
    delete[] sz_ansi;
    sz_ansi = nullptr;

    return strTemp;
}

