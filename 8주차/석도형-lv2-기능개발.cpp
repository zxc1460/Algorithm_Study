#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i = 0; i < progresses.size(); i++) {
        if((100 - progresses[i]) % speeds[i] == 0) {
            q.push((100 - progresses[i]) / speeds[i]);
        } else {
            q.push(((100 - progresses[i]) / speeds[i]) + 1);
        }
    }

    int cur = 0;

    while(!q.empty()) {
        if(cur < q.front()) {
            cur = q.front();
            answer.push_back(1);
        } else {
            answer[answer.size() - 1]++;
        }
        q.pop();
    }
    
    return answer;
}