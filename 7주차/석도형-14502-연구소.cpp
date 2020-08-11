#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m, answer;
int map[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
	queue<pair<int, int>> q;
	int temp[8][8];
	memcpy(temp, map, sizeof(map));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(temp[i][j] == 2) q.push({i, j});
		}
	}

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				q.push({nx, ny});
			}
		}
	}

	int result = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(temp[i][j] == 0) result++;
		}
	}

	answer = max(answer, result);
}

void dfs(int cnt, int x, int y) {
	if(cnt == 3) {
		bfs();
		return;
	}

	for(int i = x; i < n; i++) {
		for(int j = y; j< m; j++) {
			if(map[i][j] == 0) {
				map[i][j] = 1;
				dfs(cnt + 1, i, j + 1);
				map[i][j] = 0;
			}
		}
		y = 0;
	}
}

int main() {
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cin >> map[i][j];
	}

	dfs(0, 0, 0);

	cout << answer << '\n';

	return 0;
}