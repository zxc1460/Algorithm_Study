#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    priority_queue<int> pq;

    int day = 0, idx = 0;
    //day가 k보다 작을 때까지
    while (day < k)
    {
        if (day >= dates[idx])
        {
            pq.push(supplies[idx]);
            idx++;
        }
        if (stock == 0)
        {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        day++;
        stock--;
    }
    return answer;
}