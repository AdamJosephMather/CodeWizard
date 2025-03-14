#ifndef GETCOLORMAPTSS_H
#define GETCOLORMAPTSS_H

#include <qobject.h>

class GetColorMapTSs
{
public:
    GetColorMapTSs();

    std::unordered_map<QString, int> GetPython();
    std::unordered_map<QString, int> GetRust();
    std::unordered_map<QString, int> GetWGSL();
    std::unordered_map<QString, int> GetCpp();
    std::unordered_map<QString, int> GetTxt();
    std::unordered_map<QString, int> GetJs();
    std::unordered_map<QString, int> GetHTML();
    std::unordered_map<QString, int> GetGo();
    std::unordered_map<QString, int> GetLua();
    std::unordered_map<QString, int> GetCsharp();
    std::unordered_map<QString, int> GetGLSL();
    std::unordered_map<QString, int> GetJava();
    std::unordered_map<QString, int> GetTs();
    std::unordered_map<QString, int> GetC();
    std::unordered_map<QString, int> GetCobol();
    std::unordered_map<QString, int> GetCss();
};

#endif // GETCOLORMAPTSS_H
