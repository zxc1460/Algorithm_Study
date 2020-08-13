#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    int idx = 0;
    queue<pair<int, int>> crossing;

    while(idx < truck_weights.size() || !crossing.empty()) {
        answer++;

        if(!crossing.empty() && answer - crossing.front().second == bridge_length) {
            current_weight -= crossing.front().first;
            crossing.pop();
        }

        if(idx < truck_weights.size() && current_weight + truck_weights[idx] <= weight) {
            current_weight += truck_weights[idx];
            crossing.push({truck_weights[idx++], answer});
        }
    }

    return answer;
}
