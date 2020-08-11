#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool match(string std, string skill) {
    vector<int>v;
    for (int i = 0; i < std.length(); i++) {
        for (int j = 0; j < skill.length(); j++) {
            if (std[i] == skill[j]) {
                v.push_back(j);
            }
        }
    }
    bool ans = true;
    //v는 std에 있는 skill원소가 어떤 원소인지 적힌 벡터
    if (v.size() > 0) {
        if (v[0] != 0)
            ans = false;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1])
                ans = false;
        }
    }
    // if(ans && v.size()>0){
    //     if(v[0]!=0
    // }
    v.clear(); v.resize(0);
    return ans;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        string std = skill_trees[i];
        if (match(std, skill)) {
            cout << std << " " << skill << endl;
            answer++;
        }
    }
    return answer;
}