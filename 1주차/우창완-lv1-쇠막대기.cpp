#include <string>
#include <vector>

using namespace std;

int solution(string arrangement)
{
    int answer = 0;
    int pole = 0;
    char prev;
    for (int i = 0; i < (int)arrangement.size(); i++)
    {
        if (arrangement[i] == '(')
        {
            pole++;
        }
        else if (arrangement[i] == ')')
        {
            if (prev == '(')
            {
                pole--;
                answer += pole;
            }
            else if (prev == ')')
            {
                pole--;
                answer++;
            }
        }
        prev = arrangement[i];
    }
    return answer;
}