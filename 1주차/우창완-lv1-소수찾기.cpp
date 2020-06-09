#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
            if (i - j == 1)
            {
                answer++;
            }
        }
    }
    return answer;
}