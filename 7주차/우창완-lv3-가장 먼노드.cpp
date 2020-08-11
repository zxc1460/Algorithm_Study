#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g(20001);
vector<int> check(20001);
int height = 1;
void bfs(int cur, vector<vector<int>> g) {
    queue<int> q;
    check[cur] = 1;
    q.push(cur);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (check[y] == -1) {
                check[y] = check[x] + 1;
                q.push(y);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        check[i] = -1;
    }
    for (int i = 0; i < edge.size(); i++) {
        g[edge[i][0]].push_back(edge[i][1]);
        g[edge[i][1]].push_back(edge[i][0]);
    }

    // 2차원 벡터 sort 하면 어떻게 정렬되는지? sort(g.begin(),g.end());
    bfs(1, g);
    int max_height = -1;
    for (int i = 1; i <= n; i++) {
        max_height = max(max_height, check[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (max_height == check[i])
            answer++;
    }

    return answer;
}