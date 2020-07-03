#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 해쉬맵(key-value쌍으로 저장)을 사용하여 문제 풀이.
    // 선수 이름이 key값이 되고 참여하면 value + 1, 완주하면 value - 1
    // 해쉬맵을 순회하여 value 값이 여전히 1이면 그 선수가 완주하지 못한 것.
    unordered_map<string, int> m;
    for(string name : participant) {
        m[name]++;
    }
    for(string name : completion) {
        m[name]--;
    }

    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second == 1) {
            answer = it->first;
            break;
        }
    }

    return answer;
}

int main() {
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << '\n';
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << '\n';
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << '\n';

    return 0;
}