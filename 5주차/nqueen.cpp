#include <iostream>
using namespace std;
int n;
int answer = 0;
int col[16] = {0};
bool check(int row) {
    for (int i = 1; i < row; i++) {
        if (col[i] == col[row] || abs(col[row] - col[i]) == row - i) return false;
    }
    return true;
}
void backtracking(int row) {
    if (n < row) answer++;
    for (int i = 1; i <= n; i++) {
        col[i] = i;
        if (check(col[i])) backtracking(row + 1);
    }
}
int main() {
    cin >> n;
    backtracking(1);
    cout << answer;
    return 0;
}