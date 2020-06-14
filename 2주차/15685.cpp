#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int n, x, y, d, g, answer;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        map[y][x] = 1;
        vector<int> curve;
        curve.push_back(d);
        for(int j = 0; j < g; j++) {
            for(int k = curve.size() - 1; k >= 0; k--) {
                curve.push_back((curve[k] + 1) % 4);
            }
        }
        for(int j = 0; j < curve.size(); j++) {
            y += dy[curve[j]];
            x += dx[curve[j]];
            map[y][x] = 1;
        }
    }

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}