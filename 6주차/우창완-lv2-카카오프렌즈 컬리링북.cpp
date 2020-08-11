#include <bits/stdc++.h>

using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/1829
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int bfs(int y, int x, int m, int n, vector<vector<int>> picture, vector<vector<bool>> &check) {
    queue<pair<int, int>> q;
    int num = picture[y][x];
    int cnt = 1;
    int number = 1;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    check[y][x] = true;
    q.push(make_pair(y, x));
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (check[ny][nx] == false && picture[ny][nx] == num) {
                    q.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                    number++;
                }
            }
        }
    }
    cout << number << endl;
    return number;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>> check(m + 1, vector<bool>(n, false));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int max_num = 0;
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && check[i][j] == false) {
                int picture_cnt = bfs(i, j, m, n, picture, check);
                max_num = max(max_num, picture_cnt);
                count++;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = count;
    answer[1] = max_num;
    return answer;
}