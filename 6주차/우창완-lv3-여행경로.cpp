#include <bits/stdc++.h>
using namespace std;
int max_cnt = 0;
void DFS(string cur, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt) {
    temp.push_back(cur);
    cout << cur << endl;
    //cnt==tickets.size()로 했을 때 뒤에 처리된 dfs로 인해 answer이 갱신 되는데 이를 해결할수 있나요?
    if (cnt == tickets.size()) {
        answer = temp;
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (cur == tickets[i][0] && !visit[i]) {
            visit[i] = true;
            DFS(tickets[i][1], tickets, visit, answer, temp, cnt + 1);
            visit[i] = false;
        }
    }
    temp.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> visit(tickets.size(), false);
    vector<string> answer;
    vector<string> temp;
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, visit, answer, temp, 0);
    return answer;
}