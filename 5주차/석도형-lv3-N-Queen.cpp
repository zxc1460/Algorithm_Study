#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> chess, int n, int &answer) {
    int cur = chess.size();
    if(cur == n) {
        answer++;
        return;
    }

    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < chess.size(); j++) {
            if(i == chess[j] || abs(cur - j) == abs(i - chess[j])) {
                flag = false;
                break;
            }
        }
        if(flag) {
            chess.push_back(i);
            dfs(chess, n, answer);
            chess.pop_back();
        }
    }
}

int solution(int n) {
    int answer = 0;
    dfs({}, n, answer);
    return answer;
}