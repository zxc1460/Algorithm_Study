#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> x, vector<int> y) {
        return x[1] > y[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    int currentTime = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    sort(jobs.begin(), jobs.end());

    while(idx < jobs.size() || !pq.empty()) {
        while(idx < jobs.size() && jobs[idx][0] <= currentTime) {
            pq.push(jobs[idx++]);
        }

        if(!pq.empty()) {
            currentTime += pq.top()[1];
            answer += currentTime - pq.top()[0];
            pq.pop();
        } else if(idx < jobs.size()) {
            currentTime = jobs[idx][0];
        }
    }

    return answer / jobs.size();
}