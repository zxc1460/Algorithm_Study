#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool check[100001];
string solution(vector<string> participant, vector<string> completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    string answer = "";
    for (int i = 0; i < participant.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            return answer = participant[i];
        }
    }
    return answer = participant[participant.size()];
}
