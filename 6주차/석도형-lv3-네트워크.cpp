#include <string>
#include <vector>

using namespace std;

bool visit[200];

void dfs(int cur, int n, vector<vector<int>> computers) {
	visit[cur] = true;
	
	for(int i = 0; i < n; i++) {
		if(computers[cur][i] && !visit[i]) dfs(i, n, computers);
	}
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
    	if(!visit[i]) {
    		answer++;
    		dfs(i, n, computers);
    	}
	}
    
    return answer;
}
