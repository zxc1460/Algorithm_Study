#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> wearable;
    for (int i = 0; i < clothes.size(); i++) {
        wearable[clothes[i][1]]++;
    }
    for (auto ele : wearable) {
        answer *= ele.second + 1;
    }
    //일반 for문으로도 풀수있을까?
    return answer - 1;
}