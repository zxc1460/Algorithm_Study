#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(string cur : skill_trees) {
        string temp = "";
        
        for(char c : cur) {
            if(skill.find(c) != string::npos) {
                temp += c;
            }
        }

        if(temp == skill.substr(0, temp.size())) answer++;
    }

    return answer;
}