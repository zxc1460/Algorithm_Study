#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int island[100];

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int find(int node) {
	while(node != island[node]) {
		node = island[node];
	}

	return node;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

	sort(costs.begin(), costs.end(), cmp);

	for(int i = 0; i < n; i++) island[i] = i;

	for(int i = 0; i < costs.size(); i++) {
		int origin = find(costs[i][0]);
		int dest = find(costs[i][1]);

		if(origin != dest) {
			island[origin] = dest;
			answer += costs[i][2];
		}
	}
	
    return answer;
}