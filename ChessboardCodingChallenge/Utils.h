#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <iostream>

class Utils
{
    public:
        Utils();
        InputMessage(std::string cmd);
        bool StrLenCheck(std::string str1, std::string str2);
        void InputData(std::string &Str);
        bool CheckIfDigits(std::string x);
        std::string CheckForContinue();
};

#endif // UTILS_H
