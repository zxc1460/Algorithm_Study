#include <string>
#include <vector>

using namespace std;

// 재귀로 DFS 탐색
// numbers의 마지막 요소까지 깊이 탐색하여 sum에 더하거나 빼주면서 마지막으로 target과 같으면
// answer의 카운트 증가

void dfs(int cnt, int sum, int target, int &answer, vector<int> &numbers) {
    if(cnt == numbers.size()) {
        if(sum == target) answer++;
        return;
    }

    dfs(cnt + 1, sum + numbers[cnt], target, answer, numbers);
    dfs(cnt + 1, sum - numbers[cnt], target, answer, numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(0, 0, target, answer, numbers);

    return answer;
}