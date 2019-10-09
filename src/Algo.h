#pragma once

#include <string>
class Algo{
public:
    Algo();
    ~Algo();

    void Run();
private:
    bool IsPalindrome(std::string str);
    int FindSquaredSumOfDigits(int num);
};
