#include <string>
#include <vector>
#include <cstring>

using namespace std;

int get_loc(char c) {
    int x;
    if(c == 'A') x = 0;
    else if(c == 'C') x = 1;
    else if(c == 'F') x = 2;
    else if(c == 'J') x = 3;
    else if(c == 'M') x = 4;
    else if(c == 'N') x = 5;
    else if(c == 'R') x = 6;
    else x = 7;

    return x;
}

void dfs(vector<int> orders, vector<int> &friends, vector<string> &data, vector<bool> &visit, int &answer) {
    if(orders.size() == 8) {
        for(int i = 0; i < data.size(); i++) {
            int loc1 = get_loc(data[i][0]);
            int loc2 = get_loc(data[i][2]);
            
            int targetLength = data[i][4] - '0';
            int len = abs(orders[loc1] - orders[loc2]) - 1;

            if((data[i][3] == '=' && len != targetLength) || (data[i][3] == '<' && len >= targetLength) || (data[i][3] == '>' && len <= targetLength)) return;
        }
        answer++;
        return;
    }

    for(int i = 0; i < 8; i++) {
        if(visit[i]) continue;
        visit[i] = true;
        orders.push_back(friends[i]);
        dfs(orders, friends, data, visit, answer);
        orders.pop_back();
        visit[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<bool> visit;
    vector<int> friends = {0, 1, 2, 3, 4, 5, 6, 7};
    visit.resize(8, false);

    dfs({}, friends, data, visit, answer);

    return answer;
}