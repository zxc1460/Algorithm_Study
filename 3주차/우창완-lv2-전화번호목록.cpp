#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> m;
    for (auto p_num1 : phone_book)
    {
        for (auto p_num2 : phone_book)
        {
            if (p_num1 == p_num2)
            {
                continue;
            }
            else
            {
                if (p_num1.length() < p_num2.length())
                {
                    if (p_num1 == p_num2.substr(0, p_num1.length()))
                        return false;
                }
            }
        }
    }
    return true;
}