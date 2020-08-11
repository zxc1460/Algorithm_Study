#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
	int visit[20001] = { -1, };
	vector<int> graph[20001];
	queue<int> q;

	for(int i = 0; i < edge.size(); i++) {
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}

	q.push(1);
	visit[1] = 1;
	int max_distance = 0;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if(visit[next] == 0) {
				visit[next] = visit[cur] + 1;
				max_distance = visit[next];
				q.push(next);
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		if(visit[i] == max_distance) answer++;
	}

    return answer;
}