#include <bits/stdc++.h>
using namespace std;

int lab[8][8];
int temp[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int result = 0;

void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = lab[i][j];
            cout << temp[i][j];
        }
        cout << endl;
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }
    
	while(!q.empty()){
		int x=q.front().second;
		int y=q.front().first;
		for(int i=0;i<4; i++){
			for(int j=0; j<4; j++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx>=0&&ny>=0&&nx<m&&ny<n){
					if(temp[ny][nx]==0){
						q.push(make_pair(ny,nx));
						temp[ny][nx]=2;
					}
				}
			}
		}
	}
	
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                answer++;
            }
        }
    }
    //cout<<answer<<endl;
    result = max(result, answer);
}
void making_wall(int a, int b, int cnt) {
    if (cnt == 3) {
        bfs();
    }
    for (int i = a; i < n; i++) {
        for (int j = b; j < m; j++) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                making_wall(i, j, cnt + 1);
                lab[i][j] = 0;
            }
        }
    }
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                making_wall(i, j, 1);
                lab[i][j] = 0;
            }
        }
    }
    cout << result;
    return 0;
}