#include <string>
#include <vector>

using namespace std;

int word_count(string candi, string target) {
    int cnt = 0;

    for(int i = 0; i < candi.size(); i++) {
        if(candi[i] != target[i]) cnt++;
    }

    return cnt;
}

void dfs(string cur, string target, int cnt, int &answer, vector<string> &words, vector<bool> &visit) {
    if(cnt >= answer) return;
    if(cur == target) {
        answer = cnt;
        return;
    }

    for(int i = 0; i < words.size(); i++) {
        if(visit[i]) continue;

        if(word_count(cur, words[i]) == 1) {
            visit[i] = true;
            dfs(words[i], target, cnt + 1, answer, words, visit);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 987654321;
    vector<bool> visit(words.size(), false);

    dfs(begin, target, 0, answer, words, visit);

    return answer == 987654321 ? 0 : answer;
}