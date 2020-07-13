#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    int answer = 0;
    while (pq.top() < K)
    {
        int a = pq.top();
        pq.pop();
        if (pq.empty())
        {
            answer = -1;
            break;
        }
        int b = pq.top();
        pq.pop();
        int result = a + b * 2;
        pq.push(result);
        answer++;
    }

    return answer;
}