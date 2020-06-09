#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

bool visit[7];
set<int> result;
bool is_prime(int num) {
    if(num < 2) return false;
    if(num == 2) return true;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void recur(string number, string cur, int cnt) {
    if(cnt == number.size()) {
        if(cur != "") result.insert(stoi(cur));
        return;
    }

    for(int i = 0; i < number.size(); i++) {
        if(visit[i]) continue;
        visit[i] = true;
        recur(number, cur, cnt + 1);
        recur(number, cur + number[i], cnt + 1);
        visit[i] = false;
    }

}

int solution(string numbers) {
    int answer = 0;

    recur(numbers, "", 0);

    for(auto it = result.begin(); it != result.end(); it++) {
        if(is_prime(*it)) answer++;
    }

    return answer;
}

int main() {
    cout << solution("1234") << '\n';

    return 0;
}