#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> rest_pro;
    vector<int> days;
    vector<int> answer;
    for (int i = 0; i < progresses.size(); i++) {
        rest_pro.push_back(100 - progresses[i]);
    }
    for (int i = 0; i < rest_pro.size(); i++) {
        if (rest_pro[i] % speeds[i] != 0) {
            days.push_back(rest_pro[i] / speeds[i] + 1);
        } else {
            days.push_back(rest_pro[i] / speeds[i]);
        }
    }
    int cnt;
    for (int i = 0; i < days.size(); i = i + cnt) {
        int temp = days[i];
        // cout<<temp<<endl;
        cnt = 0;
        for (int j = i; j < days.size(); j++) {
            if (temp >= days[j]) {
                cnt++;
                continue;
            } else {
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}