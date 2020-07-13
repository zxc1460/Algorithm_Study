#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int food : scoville) {
        pq.push(food);
    }
    
    while(pq.size() > 1 && pq.top() < K) {
        answer++;

        int temp = pq.top();
        pq.pop();
        temp += pq.top() * 2;
        pq.pop();

        pq.push(temp);
    }

    if(pq.top() < K) answer = -1;

    return answer;
}